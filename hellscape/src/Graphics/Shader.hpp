#pragma once

#include <string>

class Shader {
private:
    unsigned int ID;

    unsigned int compileShader(
        unsigned int type,
        const std::string& source
    );

public:
    Shader(
        const std::string& vertexSource,
        const std::string& fragmentSource
    );

    ~Shader();

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    void use() const;
};
