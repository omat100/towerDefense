#pragma once

#include "Renderer/Mesh.hpp"
#include "Graphics/Shader.hpp"
#include "Core/Transform.hpp"

struct GLFWwindow;

class Renderer {
private:
    GLFWwindow* window;

public:
    explicit Renderer(GLFWwindow* window);

    void beginFrame();
    void draw(const Mesh& mesh, const Shader& shader, const Transform& transform);
    void endFrame();
};