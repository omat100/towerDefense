
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Graphics/Shader.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Mesh.hpp"

#include <iostream>
#include <vector>
#include <string>

const std::string vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;

void main() {
    gl_Position = vec4(aPos, 1.0);
}
)";

const std::string fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;

void main() {
    FragColor = vec4(0.2, 0.7, 1.0, 1.0);
}
)";

int main() {
    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(
        1280, 720, "Hellscape", nullptr, nullptr
    );

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
        std::cerr << "GLAD initialization failed\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    {
        Shader shader(vertexShaderSource, fragmentShaderSource);

        std::vector<float> triangleVertices = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };

        std::vector<float> rectangleVertices = {
            -0.8f, -0.5f, 0.0f,
            -0.2f, -0.5f, 0.0f,
            -0.2f,  0.5f, 0.0f,

            -0.8f, -0.5f, 0.0f,
            -0.2f,  0.5f, 0.0f,
            -0.8f,  0.5f, 0.0f
        };

        Mesh triangle(triangleVertices);
        Mesh rectangle(rectangleVertices);

        Renderer renderer(window);

        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();

            renderer.beginFrame();
            renderer.draw(triangle, shader);
            renderer.draw(rectangle, shader);
            renderer.endFrame();
        }
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
