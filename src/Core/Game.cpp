#include "Game.hpp"
#include <SFML/Graphics.hpp>

#include "../defense/Wall.hpp"
#include "../defense/Cannon.hpp"

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
    renderer.clear();

    renderer.draw(defense::Wall{types::Levels::Level1, 100.f, 100.f});
    renderer.draw(defense::Cannon{types::Levels::Level1, 100.f, 100.f});

    renderer.display();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}