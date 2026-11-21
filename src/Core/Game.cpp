#include "Game.hpp"

#include <SFML/Graphics.hpp>

// std
#include <memory>

#include "../attack/Soldier.hpp"
#include "../attack/Tank.hpp"

#include "../defense/Wall.hpp"
#include "../defense/Cannon.hpp"
#include "../defense/Tower.hpp"

Game::Game()
    : window(1000, 700, "My Game"),
      renderer(window.getNativeWindow()) {

    // Attackers start on the left and walk towards the defenses.
    world.addAttack(std::make_unique<attack::Soldier>(types::Levels::Level1, 60.f, 300.f));
    world.addAttack(std::make_unique<attack::Tank>(types::Levels::Level1, 30.f, 450.f));
    world.addAttack(std::make_unique<attack::Soldier>(types::Levels::Level1, 90.f, 150.f));

    // Defenses hold the right side. The wall is the first engagement; the
    // cannon and tower are placed far enough back that they only open fire
    // after the wall has fallen.
    world.addDefense(std::make_unique<defense::Wall>(types::Levels::Level1, 500.f, 300.f));
    world.addDefense(std::make_unique<defense::Cannon>(types::Levels::Level1, 850.f, 500.f));
    world.addDefense(std::make_unique<defense::Tower>(types::Levels::Level1, 850.f, 100.f));
}

void Game::processEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update(float deltaTime) {
    world.update(deltaTime);
}

void Game::render() {
    renderer.clear();

    for (const auto &unit : world.getAttacks()) {
        if (unit && unit->isAlive()) renderer.draw(*unit);
    }

    for (const auto &unit : world.getDefenses()) {
        if (unit && unit->isAlive()) renderer.draw(*unit);
    }

    renderer.display();
}

void Game::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        processEvents();

        // Clamp dt so a stalled frame cannot teleport units through the map.
        float deltaTime = clock.restart().asSeconds();
        if (deltaTime > 0.05f) deltaTime = 0.05f;

        update(deltaTime);
        render();
    }
}
