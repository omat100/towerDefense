#pragma once
#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow window;
    sf::Event event;

    void processEvents();
    void update();
    void render();

public:
    Game();
    void run();
};