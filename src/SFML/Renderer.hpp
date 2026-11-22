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
    void Renderer::drawGhost(defense::DefenseType type, types::Pos pos, bool valid);
    void Renderer::drawGhost(attack::AttackType type, types::Pos pos, bool valid);
};
