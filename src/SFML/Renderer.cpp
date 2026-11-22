#include "Renderer.hpp"

// std
#include <algorithm>

namespace {
    void drawHealthBar(sf::RenderWindow &window, types::Pos pos, float width,
                       float yOffset, int health, int maxHealth){
        if(maxHealth <= 0) return;

        const float ratio = std::clamp(
            static_cast<float>(health) / static_cast<float>(maxHealth), 0.f, 1.f);

        sf::RectangleShape background({width, 4.f});
        background.setPosition(pos.x - width / 2.f, pos.y + yOffset);
        background.setFillColor(sf::Color(30, 30, 30));
        window.draw(background);

        sf::RectangleShape fill({width * ratio, 4.f});
        fill.setPosition(pos.x - width / 2.f, pos.y + yOffset);
        fill.setFillColor(sf::Color(70, 210, 90));
        window.draw(fill);
    }
}

Renderer::Renderer(sf::RenderWindow& window)
    : window(window) {}

void Renderer::clear(const sf::Color& color) {
    window.clear(color);
}

void Renderer::display() {
    window.display();
}

void Renderer::draw(const attack::Block& unit) {
    const types::Pos pos = unit.getPosition();

    float radius = 9.f;
    sf::Color color = sf::Color(80, 200, 120);

    switch (unit.getAttackType()) {
        case attack::AttackType::soldier:
            radius = 9.f;
            color = sf::Color(80, 200, 120);
            break;
        case attack::AttackType::tank:
            radius = 13.f;
            color = sf::Color(210, 140, 40);
            break;
        case attack::AttackType::balloon:
            radius = 10.f;
            color = sf::Color(120, 180, 255);
            break;
    }

    sf::CircleShape shape(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(pos.x, pos.y);
    shape.setFillColor(color);
    window.draw(shape);

    drawHealthBar(window, pos, radius * 2.f, -radius - 10.f,
                  unit.getHealth(), unit.getMaxHealth());
}

void Renderer::draw(const defense::Block& unit) {
    const types::Pos pos = unit.getPosition();

    float halfWidth = 40.f;
    float yOffset = -50.f;

    switch (unit.getDefenseType()) {
        case defense::DefenseType::wall: {
            const float size = 80.f;
            sf::RectangleShape shape({size, size});
            shape.setOrigin(size / 2.f, size / 2.f);
            shape.setPosition(pos.x, pos.y);
            shape.setFillColor(sf::Color(60, 90, 200));
            window.draw(shape);

            halfWidth = size / 2.f;
            yOffset = -size / 2.f - 10.f;
            break;
        }
        case defense::DefenseType::cannon: {
            const float radius = 25.f;
            sf::CircleShape shape(radius);
            shape.setOrigin(radius, radius);
            shape.setPosition(pos.x, pos.y);
            shape.setFillColor(sf::Color(210, 60, 60));
            window.draw(shape);

            halfWidth = radius;
            yOffset = -radius - 10.f;
            break;
        }
        case defense::DefenseType::tower: {
            const float size = 60.f;
            sf::RectangleShape shape({size, size});
            shape.setOrigin(size / 2.f, size / 2.f);
            shape.setPosition(pos.x, pos.y);
            shape.setFillColor(sf::Color(150, 80, 200));
            window.draw(shape);

            halfWidth = size / 2.f;
            yOffset = -size / 2.f - 10.f;
            break;
        }
        case defense::DefenseType::soldier: {
            const float radius = 12.f;
            sf::CircleShape shape(radius);
            shape.setOrigin(radius, radius);
            shape.setPosition(pos.x, pos.y);
            shape.setFillColor(sf::Color(90, 160, 220));
            window.draw(shape);

            halfWidth = radius;
            yOffset = -radius - 10.f;
            break;
        }
        case defense::DefenseType::townHall: {
            const float width = 120.f;
            const float height = 80.f;
            sf::RectangleShape shape({width, height});
            shape.setOrigin(width / 2.f, height / 2.f);
            shape.setPosition(pos.x, pos.y);
            shape.setFillColor(sf::Color(220, 190, 70));
            window.draw(shape);

            halfWidth = width / 2.f;
            yOffset = -height / 2.f - 10.f;
            break;
        }
    }

    drawHealthBar(window, pos, halfWidth * 2.f, yOffset,
                  unit.getHealth(), unit.getMaxHealth());
}

void Renderer::drawGhost(defense::Block type, types::Pos pos, bool valid) {
    auto col = [&](sf::Color c) {
        if (!valid) c = sf::Color(255, 60, 60);
        c.a = 130;
        return c;
    };
    auto rect = [&](float w, float h, sf::Color c) {
        sf::RectangleShape s({w, h});
        s.setOrigin(w / 2.f, h / 2.f);
        s.setPosition(pos.x, pos.y);
        s.setFillColor(col(c));
        window.draw(s);
    };
    auto circle = [&](float r, sf::Color c) {
        sf::CircleShape s(r);
        s.setOrigin(r, r);
        s.setPosition(pos.x, pos.y);
        s.setFillColor(col(c));
        window.draw(s);
    };

    switch (type.getDefenseType()) {
        case defense::DefenseType::wall:     rect(80.f, 80.f, sf::Color(60, 90, 200)); break;
        case defense::DefenseType::cannon:   circle(25.f, sf::Color(210, 60, 60));     break;
        case defense::DefenseType::tower:    rect(60.f, 60.f, sf::Color(150, 80, 200)); break;
        case defense::DefenseType::soldier:  circle(12.f, sf::Color(90, 160, 220));    break;
        case defense::DefenseType::townHall: rect(120.f, 80.f, sf::Color(220, 190, 70)); break;
    }
}

void Renderer::drawGhost(attack::Block type, types::Pos pos, bool valid) {
    float r = 9.f;
    sf::Color c(80, 200, 120);
    switch (type.getAttackType()) {
        case attack::AttackType::soldier: r = 9.f;  c = sf::Color(80, 200, 120);  break;
        case attack::AttackType::tank:    r = 13.f; c = sf::Color(210, 140, 40);  break;
        case attack::AttackType::balloon: r = 10.f; c = sf::Color(120, 180, 255); break;
    }
    if (!valid) c = sf::Color(255, 60, 60);
    c.a = 130;

    sf::CircleShape s(r);
    s.setOrigin(r, r);
    s.setPosition(pos.x, pos.y);
    s.setFillColor(c);
    window.draw(s);
}
