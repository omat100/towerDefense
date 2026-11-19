#include "InputHandler.hpp"

bool InputHandler::isKeyPressed(sf::Keyboard::Key key) const {
    return sf::Keyboard::isKeyPressed(key);
}

bool InputHandler::isMouseButtonPressed(sf::Mouse::Button button) const {
    return sf::Mouse::isButtonPressed(button);
}

sf::Vector2i InputHandler::getMousePosition(const Window& window) const {
    return sf::Mouse::getPosition(window.getNativeWindow());
}