#pragma once

// types
#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

class GameObject {
private:
    types::Pos position;

protected:
    GameObject(float x, float y)
        : position{x, y} {}

public:
    virtual ~GameObject() = default;

    types::Pos getPosition() const {
        return position;
    }

    void setPosition(float x, float y) {
        position = {x, y};
    }

    void setPosition(types::Pos newPosition) {
        position = newPosition;
    }

    virtual void update(float deltaTime) = 0;
};
