#include "Core/Transform.hpp"
#include <glm/gtc/matrix_transform.hpp>

Transform::Transform()
    : position(0.0f, 0.0f),
      scale(1.0f, 1.0f),
      rotation(0.0f) {}

void Transform::setPosition(float x, float y) {
    position = glm::vec2(x, y);
}

void Transform::setScale(float x, float y) {
    scale = glm::vec2(x, y);
}

void Transform::setRotation(float angle) {
    rotation = angle;
}

glm::mat4 Transform::getModelMatrix() const {
    glm::mat4 model(1.0f);

    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0, 0, 1));
    model = glm::scale(model, glm::vec3(scale, 1.0f));

    return model;
}