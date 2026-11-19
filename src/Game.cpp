#include "Game.hpp"

Game::Game()
    : window(sf::VideoMode(1000, 700), "Tower Defense") {
    window.setFramerateLimit(60);
}

void Game::processEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {

}

void Game::render() {
    window.clear(sf::Color(30, 30, 30));

    sf::RectangleShape cube(sf::Vector2f(50.f, 50.f));
    cube.setFillColor(sf::Color::Blue);
    cube.setPosition(475.f, 325.f);

    window.draw(cube);

    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}