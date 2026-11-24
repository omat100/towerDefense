#pragma once

#include "Renderer/Mesh.hpp"
#include "Graphics/Shader.hpp"

struct GLFWwindow;

class Renderer {
private:
    GLFWwindow* window;

public:
    explicit Renderer(GLFWwindow* window);

    void beginFrame();
    void draw(const Mesh& mesh, const Shader& shader);
    void endFrame();
};