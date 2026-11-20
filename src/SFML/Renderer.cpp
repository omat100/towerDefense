#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow& window)
    : window(window) {}

void Renderer::clear(const sf::Color& color) {
    window.clear(color);
}

void Renderer::display() {
    window.display();
}

void Renderer::draw(const defense::Wall& wall) {
    Pos pos = wall.getPosition();

    sf::RectangleShape shape({100.f, 100.f});
    shape.setPosition(pos.x, pos.y);
    shape.setFillColor(sf::Color::Blue);

    window.draw(shape); // Pass the SFML shape, NOT wall
}

void Renderer::draw(const defense::Cannon& cannon) {
    Pos pos = cannon.getPosition();

    sf::CircleShape shape(25.f);
    shape.setPosition(pos.x, pos.y);
    shape.setFillColor(sf::Color::Red);

    window.draw(shape); // Pass the SFML shape, NOT cannon
}