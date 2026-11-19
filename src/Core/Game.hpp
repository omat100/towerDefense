#pragma once

#include "../SFML/Window.hpp"
#include "../Core/Renderer.hpp"
#include "../SFML/InputHandler.hpp"

#include "../defense/Wall.hpp"
#include "../defense/Cannon.hpp"
#include "../defense/DefenseType.hpp"

class Game {
private:
    Window window;
    Renderer renderer;
    InputHandler input;

    void processEvents();
    void update();
    void render();

    // game objects

    defense::Wall wall{defense::Levels::Level1, 100.f, 100.f};
    defense::Cannon cannon{defense::Levels::Level1, 300.f, 200.f};

public:
    Game();
    void run();
};