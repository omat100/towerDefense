#include "SceneBuilderUI.hpp"
#include "../../defense/Block.hpp"

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
        {defense::DefenseType::soldier,  "soldier",  12.f, 12.f},
        {defense::DefenseType::townHall, "townHall", 60.f, 40.f},
    };

    const TypeInfo &info(defense::DefenseType t) {
        for (const auto &i : kTypes)
            if (i.type == t) return i;
        return kTypes[0];
    }

    bool overlap(const TypeInfo &a, types::Pos pa, const TypeInfo &b, types::Pos pb) {
        return std::abs(pa.x - pb.x) < a.halfW + b.halfW &&
               std::abs(pa.y - pb.y) < a.halfH + b.halfH;
    }

    // >>> The ONE place that depends on how a Block is constructed. <<<
    // Change this line to match your real constructor.
    defense::Block makeBlock(defense::DefenseType type, types::Pos pos) {
        return defense::Block(type, pos);
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
        for (Placement *p : data.defenses) delete p;
        data.defenses.clear();
    }

    SceneBuilderUI::SceneBuilderUI(SceneData &data) : data(data) {}

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
            if (!p) continue;
            if (overlap(a, pos, info(p->type.getDefenseType()), p->positon)) return false;
        }
        return true;
    }

    void SceneBuilderUI::placeAt(types::Pos pos) {
        if (!canPlace(selected, pos))
            return;
        data.defenses.push_back(new Placement{makeBlock(selected, pos), pos});
    }

    void SceneBuilderUI::removeAt(types::Pos pos) {
        // backwards so the most recently placed (topmost) one goes first
        for (int i = static_cast<int>(data.defenses.size()) - 1; i >= 0; --i) {
            Placement *p = data.defenses[i];
            if (!p) continue;
            const TypeInfo &t = info(p->type.getDefenseType());
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
            const types::Pos p = snap(mouseWorld(window));
            renderer.drawGhost(selected, p, canPlace(selected, p));
        }
    }

    void SceneBuilderUI::save(const std::string &path) {
        std::ofstream out(path);
        if (!out) { status = "Save failed"; return; }
        for (const Placement *p : data.defenses) {
            if (!p) continue;
            out << info(p->type.getDefenseType()).name << ' '
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
                if (name == t.name) {
                    const types::Pos pos{x, y};
                    loaded.push_back(new Placement{makeBlock(t.type, pos), pos});
                }
            }
        }

        clearScene(data);
        data.defenses = std::move(loaded);
        status = "Loaded " + std::to_string(data.defenses.size()) + " items";
    }
} // namespace sceneBuilder