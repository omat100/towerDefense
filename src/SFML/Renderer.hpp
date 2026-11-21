#pragma once

#include <SFML/Graphics.hpp>

#include "../attack/Block.hpp"
#include "../defense/Block.hpp"

class Renderer {
private:
    sf::RenderWindow& window;

public:
    explicit Renderer(sf::RenderWindow& window);

    void clear(const sf::Color& color = sf::Color::Black);
    void display();

    void draw(const attack::Block& unit);
    void draw(const defense::Block& unit);
};
