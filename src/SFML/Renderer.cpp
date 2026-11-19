#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow& window)
    : window(window) {}

void Renderer::clear(const sf::Color& color) {
    window.clear(color);
}

void Renderer::draw(const sf::Drawable& drawable) {
    window.draw(drawable);
}

void Renderer::display() {
    window.display();
}