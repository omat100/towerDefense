#pragma once

#include "Renderer/Triangle.hpp"
#include "Graphics/Shader.hpp"

struct GLFWwindow;

class Renderer {
private:
    GLFWwindow* window;

public:
    explicit Renderer(GLFWwindow* window);

    void beginFrame();
    void draw(const Triangle& triangle, const Shader& shader);
    void endFrame();
};