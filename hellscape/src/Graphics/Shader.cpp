#include "Shader.hpp"
#include <glad/gl.h>
#include <iostream>

unsigned int Shader::compileShader(
    unsigned int type,
    const std::string& source
) {
    unsigned int shader = glCreateShader(type);

    const char* sourceCode = source.c_str();
    glShaderSource(shader, 1, &sourceCode, nullptr);
    glCompileShader(shader);

    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader compilation failed:\n"
                  << infoLog << '\n';
    }

    return shader;
}

Shader::Shader(
    const std::string& vertexSource,
    const std::string& fragmentSource
) {
    unsigned int vertex = compileShader(
        GL_VERTEX_SHADER, vertexSource
    );

    unsigned int fragment = compileShader(
        GL_FRAGMENT_SHADER, fragmentSource
    );

    ID = glCreateProgram();

    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    int success;
    char infoLog[512];

    glGetProgramiv(ID, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cerr << "Shader linking failed:\n"
                  << infoLog << '\n';
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() {
    glDeleteProgram(ID);
}

void Shader::use() const {
    glUseProgram(ID);
}
