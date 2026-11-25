#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Graphics/Shader.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Mesh.hpp"
#include "Core/Transform.hpp"
#include "Core/Camera.hpp"

#include <iostream>
#include <vector>
#include <string>

const std::string vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 projection;

void main() {
    gl_Position = projection * model * vec4(aPos, 1.0);
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

    glViewport(0, 0, 1280, 720);

    {
        Shader shader(vertexShaderSource, fragmentShaderSource);

        std::vector<float> triangleVertices = {
            -50.0f, -50.0f, 0.0f,
             50.0f, -50.0f, 0.0f,
              0.0f,  50.0f, 0.0f
        };

        std::vector<float> rectangleVertices = {
            -50.0f, -50.0f, 0.0f,
             50.0f, -50.0f, 0.0f,
             50.0f,  50.0f, 0.0f,

            -50.0f, -50.0f, 0.0f,
             50.0f,  50.0f, 0.0f,
            -50.0f,  50.0f, 0.0f
        };

        Mesh triangle(triangleVertices);
        Mesh rectangle(rectangleVertices);

        Transform triangleTransform;
        triangleTransform.setPosition(300.0f, 300.0f);

        Transform rectangleTransform;
        rectangleTransform.setPosition(800.0f, 300.0f);
        rectangleTransform.setRotation(20.0f);

        Camera camera(1280.0f, 720.0f);
        Renderer renderer(window);

        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();

            renderer.beginFrame();

            renderer.draw(triangle, shader, triangleTransform, camera);
            renderer.draw(rectangle, shader, rectangleTransform, camera);

            renderer.endFrame();
        }
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
