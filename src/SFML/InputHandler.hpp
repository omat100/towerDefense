#pragma once

#include <SFML/Graphics.hpp>
#include "Window.hpp"

class InputHandler {
public:
    bool isKeyPressed(sf::Keyboard::Key key) const;

    bool isMouseButtonPressed(sf::Mouse::Button button) const;

    sf::Vector2i getMousePosition(const Window& window) const;
};