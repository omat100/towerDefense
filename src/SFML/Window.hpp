#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Window {
private:
    sf::RenderWindow window;

public:
    Window(unsigned int width, unsigned int height, const std::string& title);

    bool isOpen() const;
    void close();
    bool pollEvent(sf::Event& event);

    sf::RenderWindow& getNativeWindow() const;
};