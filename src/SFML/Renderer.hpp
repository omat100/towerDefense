#pragma once

#include <SFML/Graphics.hpp>
#include "../defense/Wall.hpp"
#include "../defense/Cannon.hpp"

class Renderer {
private:
    sf::RenderWindow& window;

public:
    explicit Renderer(sf::RenderWindow& window);

    void clear(const sf::Color& color = sf::Color::Black);
    void display();

    void draw(const defense::Wall& wall);
    void draw(const defense::Cannon& cannon);
};