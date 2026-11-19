#pragma once

struct Pos {
    float x;
    float y;
};

class GameObject {
private:
    Pos position;

protected:
    GameObject(float x, float y)
        : position{x, y} {}

public:
    virtual ~GameObject() = default;

    Pos getPosition() const {
        return position;
    }

    void setPosition(float x, float y) {
        position = {x, y};
    }

    virtual void update(float deltaTime) = 0;
};