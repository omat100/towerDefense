#pragma once

#include "../SFML/Window.hpp"
#include "../SFML/Renderer.hpp"
#include "../SFML/InputHandler.hpp"

class Game {
private:
    Window window;
    Renderer renderer;
    InputHandler input;

    void processEvents();
    void update();
    void render();

public:
    Game();
    void run();
};