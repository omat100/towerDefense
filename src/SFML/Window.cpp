#include "Window.hpp"

Window::Window(unsigned int width, unsigned int height, const std::string& title)
    : window(sf::VideoMode(width, height), title) {
    window.setFramerateLimit(60);
}

bool Window::isOpen() const {
    return window.isOpen();
}

void Window::close() {
    window.close();
}

bool Window::pollEvent(sf::Event& event) {
    return window.pollEvent(event);
}

sf::RenderWindow& Window::getNativeWindow() const {
    return const_cast<sf::RenderWindow&>(window);
}