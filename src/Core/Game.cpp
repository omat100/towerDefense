#include "Game.hpp"
#include <SFML/Graphics.hpp>

Game::Game()
    : window(1000, 700, "My Game"),
      renderer(window.getNativeWindow()) {}

void Game::processEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {

}

void Game::render() {
    renderer.clear(sf::Color(30, 30, 30));

    sf::RectangleShape cube({50.f, 50.f});
    cube.setFillColor(sf::Color::Blue);
    cube.setPosition(475.f, 325.f);

    renderer.draw(cube);

    renderer.display();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}