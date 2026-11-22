#include "SceneBuilderUI.hpp"

// concrete defenses (names guessed, fix to match your files)
#include "../../defense/Wall.hpp"
#include "../../defense/Cannon.hpp"
#include "../../defense/Tower.hpp"
// #include "../../defense/Soldier.hpp"
#include "../../defense/TownHall.hpp"

#include <imgui.h>
#include <imgui-SFML.h>

#include <cmath>
#include <fstream>

namespace {
    struct TypeInfo {
        defense::DefenseType type;
        const char *name;
        float halfW, halfH;   // mirrors the shape sizes in Renderer.cpp
    };

    const TypeInfo kTypes[] = {
        {defense::DefenseType::wall,     "wall",     40.f, 40.f},
        {defense::DefenseType::cannon,   "cannon",   25.f, 25.f},
        {defense::DefenseType::tower,    "tower",    30.f, 30.f},
        // {defense::DefenseType::soldier,  "soldier",  12.f, 12.f},
        {defense::DefenseType::townHall, "townHall", 60.f, 40.f},
    };
    const int kTypeCount = sizeof(kTypes) / sizeof(kTypes[0]);

    int indexOf(defense::DefenseType t) {
        for (int i = 0; i < kTypeCount; ++i)
            if (kTypes[i].type == t) return i;
        return 0;
    }

    const TypeInfo &info(defense::DefenseType t) { return kTypes[indexOf(t)]; }

    bool overlap(const TypeInfo &a, types::Pos pa, const TypeInfo &b, types::Pos pb) {
        return std::abs(pa.x - pb.x) < a.halfW + b.halfW &&
               std::abs(pa.y - pb.y) < a.halfH + b.halfH;
    }

    // >>> The ONE place that depends on the concrete defense constructors. <<<
    // If your game already has a factory/spawn function, call that here instead.
    std::unique_ptr<defense::Block> makeDefense(defense::DefenseType type, types::Pos pos) {
        switch (type) {
            case defense::DefenseType::wall:
                return std::make_unique<defense::Wall>(pos.x, pos.y);
            case defense::DefenseType::cannon:
                return std::make_unique<defense::Cannon>(pos.x, pos.y);
            case defense::DefenseType::tower:
                return std::make_unique<defense::Tower>(pos.x, pos.y);
            // case defense::DefenseType::soldier:
            //     return std::make_unique<defense::Soldier>(pos.x, pos.y);
            case defense::DefenseType::townHall:
                return std::make_unique<defense::TownHall>(pos.x, pos.y);
        }
        return nullptr;
    }

    void drawGrid(sf::RenderWindow &window, int cell) {
        const sf::Vector2u size = window.getSize();
        sf::VertexArray lines(sf::Lines);
        const sf::Color c(255, 255, 255, 18);
        for (int x = 0; x <= static_cast<int>(size.x); x += cell) {
            lines.append({{static_cast<float>(x), 0.f}, c});
            lines.append({{static_cast<float>(x), static_cast<float>(size.y)}, c});
        }
        for (int y = 0; y <= static_cast<int>(size.y); y += cell) {
            lines.append({{0.f, static_cast<float>(y)}, c});
            lines.append({{static_cast<float>(size.x), static_cast<float>(y)}, c});
        }
        window.draw(lines);
    }
}

namespace sceneBuilder {

    void clearScene(SceneData &data) {
        for (Placement *p : data.defenses) delete p;   // frees the Block too
        data.defenses.clear();
    }

    SceneBuilderUI::SceneBuilderUI(SceneData &data) : data(data) {
        for (const auto &t : kTypes)
            previews.push_back(makeDefense(t.type, types::Pos{0.f, 0.f}));
    }

    types::Pos SceneBuilderUI::mouseWorld(sf::RenderWindow &window) const {
        const sf::Vector2f p = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        return types::Pos{p.x, p.y};
    }

    types::Pos SceneBuilderUI::snap(types::Pos p) const {
        if (!snapOn) return p;
        const float c = static_cast<float>(cell);
        return types::Pos{std::round(p.x / c) * c, std::round(p.y / c) * c};
    }

    bool SceneBuilderUI::canPlace(defense::DefenseType type, types::Pos pos) const {
        const TypeInfo &a = info(type);
        for (const Placement *p : data.defenses) {
            if (!p || !p->type) continue;
            if (overlap(a, pos, info(p->type->getDefenseType()), p->positon)) return false;
        }
        return true;
    }

    void SceneBuilderUI::placeAt(types::Pos pos) {
        if (!canPlace(selected, pos)) return;

        auto block = makeDefense(selected, pos);
        if (!block) return;
        data.defenses.push_back(new Placement{std::move(block), pos});
    }

    void SceneBuilderUI::removeAt(types::Pos pos) {
        // backwards so the most recently placed (topmost) one goes first
        for (int i = static_cast<int>(data.defenses.size()) - 1; i >= 0; --i) {
            Placement *p = data.defenses[i];
            if (!p || !p->type) continue;
            const TypeInfo &t = info(p->type->getDefenseType());
            if (std::abs(pos.x - p->positon.x) <= t.halfW &&
                std::abs(pos.y - p->positon.y) <= t.halfH) {
                delete p;
                data.defenses.erase(data.defenses.begin() + i);
                return;
            }
        }
    }

    void SceneBuilderUI::handleEvent(const sf::Event &e, sf::RenderWindow &window) {
        if (e.type != sf::Event::MouseButtonPressed) return;
        if (ImGui::GetIO().WantCaptureMouse) return;   // click landed on the panel

        const types::Pos m = mouseWorld(window);
        if (e.mouseButton.button == sf::Mouse::Left)
            placeAt(snap(m));
        else if (e.mouseButton.button == sf::Mouse::Right)
            removeAt(m);
    }

    void SceneBuilderUI::drawPanel() {
        ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
        ImGui::Begin("Scene Builder");

        ImGui::Text("Palette");
        for (const auto &t : kTypes) {
            if (ImGui::RadioButton(t.name, selected == t.type))
                selected = t.type;
        }

        ImGui::Separator();
        ImGui::Checkbox("Snap to grid", &snapOn);
        ImGui::SliderInt("Cell size", &cell, 10, 80);

        ImGui::Separator();
        ImGui::Text("Placed: %d", static_cast<int>(data.defenses.size()));
        if (ImGui::Button("Clear")) clearScene(data);
        ImGui::SameLine();
        if (ImGui::Button("Save")) save("scene.txt");
        ImGui::SameLine();
        if (ImGui::Button("Load")) load("scene.txt");

        if (!status.empty()) ImGui::TextWrapped("%s", status.c_str());

        ImGui::Separator();
        ImGui::TextDisabled("LMB place | RMB delete");
        ImGui::End();
    }

    void SceneBuilderUI::draw(Renderer &renderer, sf::RenderWindow &window) {
        drawGrid(window, cell);

        sceneMaker(&data, renderer);   // your existing function draws the placed items

        const sf::Vector2i px = sf::Mouse::getPosition(window);
        const bool inside = px.x >= 0 && px.y >= 0 &&
                            px.x < static_cast<int>(window.getSize().x) &&
                            px.y < static_cast<int>(window.getSize().y);
        if (inside && !ImGui::GetIO().WantCaptureMouse) {
            const auto &preview = previews[indexOf(selected)];
            if (preview) {
                const types::Pos p = snap(mouseWorld(window));
                renderer.drawGhost(*preview, p, canPlace(selected, p));
            }
        }
    }

    void SceneBuilderUI::save(const std::string &path) {
        std::ofstream out(path);
        if (!out) { status = "Save failed"; return; }
        for (const Placement *p : data.defenses) {
            if (!p || !p->type) continue;
            out << info(p->type->getDefenseType()).name << ' '
                << p->positon.x << ' ' << p->positon.y << '\n';
        }
        status = "Saved " + std::to_string(data.defenses.size()) + " items";
    }

    void SceneBuilderUI::load(const std::string &path) {
        std::ifstream in(path);
        if (!in) { status = "No " + path + " found"; return; }

        std::vector<Placement *> loaded;
        std::string name;
        float x, y;
        while (in >> name >> x >> y) {
            for (const auto &t : kTypes) {
                if (name != t.name) continue;
                const types::Pos pos{x, y};
                auto block = makeDefense(t.type, pos);
                if (block) loaded.push_back(new Placement{std::move(block), pos});
            }
        }

        clearScene(data);
        data.defenses = std::move(loaded);
        status = "Loaded " + std::to_string(data.defenses.size()) + " items";
    }

} // namespace sceneBuilder