#pragma once

#include "../SFML/Window.hpp"
#include "../SFML/Renderer.hpp"
#include "../SFML/InputHandler.hpp"

#include "GameWorld.hpp"

class Game {
private:
    Window window;
    Renderer renderer;
    InputHandler input;
    GameWorld world;

    void processEvents();
    void update(float deltaTime);
    void render();

public:
    Game();
    void run();
};
