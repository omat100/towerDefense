#pragma once

#include <string>
#include <glm/glm.hpp>

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
    
    void setMat4(const std::string& name, const glm::mat4& matrix) const;
    void use() const;
};
