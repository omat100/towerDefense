#include "../Screen.hpp"
#include "SceneBuilderUI.hpp"

#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

void sceneBuilder::runScreen() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Scene Builder");
    window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(window)) {
        return;
    }

    Renderer renderer(window);
    SceneData data;
    data.userName = "scene";
    SceneBuilderUI ui(data);
    sf::Clock dt;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            ImGui::SFML::ProcessEvent(window, e);
            if (e.type == sf::Event::Closed) window.close();
            ui.handleEvent(e, window);
        }

        ImGui::SFML::Update(window, dt.restart());
        ui.drawPanel();

        renderer.clear(sf::Color(25, 25, 30));
        ui.draw(renderer, window);
        ImGui::SFML::Render(window);   // before display(), which Renderer calls
        renderer.display();
    }

    clearScene(data);
    ImGui::SFML::Shutdown();
}