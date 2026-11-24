#pragma once

#include <glm/glm.hpp>

class Transform {
private:
    glm::vec2 position;
    glm::vec2 scale;
    float rotation;

public:
    Transform();

    void setPosition(float x, float y);
    void setScale(float x, float y);
    void setRotation(float angle);

    glm::mat4 getModelMatrix() const;
};