#include "Renderer/Renderer.hpp"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

Renderer::Renderer(GLFWwindow* window) : window(window) {}

void Renderer::beginFrame() {
    glClearColor(0.08f, 0.08f, 0.10f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Triangle& triangle, const Shader& shader) {
    shader.use();
    triangle.draw();
}

void Renderer::endFrame() {
    glfwSwapBuffers(window);
}