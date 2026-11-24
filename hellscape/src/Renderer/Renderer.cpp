#include "Renderer/Renderer.hpp"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

Renderer::Renderer(GLFWwindow* window) : window(window) {}

void Renderer::beginFrame() {
    glClearColor(0.08f, 0.08f, 0.10f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Mesh& mesh, const Shader& shader, const Transform& transform) {
    shader.use();
    shader.setMat4("model", transform.getModelMatrix());
    mesh.draw();
}

void Renderer::endFrame() {
    glfwSwapBuffers(window);
}