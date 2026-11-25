#include "Core/Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float width, float height)
    : width(width), height(height) {
    updateProjection();
}

void Camera::updateProjection() {
    projection = glm::ortho(
        0.0f, width,
        height, 0.0f,
        -1.0f, 1.0f
    );
}

void Camera::setViewport(float width, float height) {
    this->width = width;
    this->height = height;

    updateProjection();
}

const glm::mat4& Camera::getProjectionMatrix() const {
    return projection;
}