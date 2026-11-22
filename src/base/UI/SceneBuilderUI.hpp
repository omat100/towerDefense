#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>

#include "../SceneCreator.hpp"

namespace sceneBuilder {

    // SceneData owns its Placement pointers. Call this when you're done with a scene.
    void clearScene(SceneData &data);

    class SceneBuilderUI {
    public:
        explicit SceneBuilderUI(SceneData &data);

        void handleEvent(const sf::Event &e, sf::RenderWindow &window);
        void drawPanel();                                        // ImGui panel
        void draw(Renderer &renderer, sf::RenderWindow &window); // grid, scene, ghost

    private:
        types::Pos mouseWorld(sf::RenderWindow &window) const;
        types::Pos snap(types::Pos p) const;
        bool canPlace(defense::DefenseType type, types::Pos pos) const;
        void placeAt(types::Pos pos);
        void removeAt(types::Pos pos);
        void save(const std::string &path);
        void load(const std::string &path);

        SceneData &data;
        defense::DefenseType selected = defense::DefenseType::cannon;
        bool snapOn = true;
        int cell = 40;
        std::string status;

        // one throwaway Block per type, used only for the hover ghost
        std::vector<std::unique_ptr<defense::Block>> previews;
    };

} // namespace sceneBuilder