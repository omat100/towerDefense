#pragma once

#include <glm/glm.hpp>

class Camera {
private:
    glm::mat4 projection;

    float width;
    float height;

    void updateProjection();

public:
    Camera(float width, float height);

    void setViewport(float width, float height);

    const glm::mat4& getProjectionMatrix() const;
};