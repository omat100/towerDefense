#pragma once

#include <vector>

class Mesh {
private:
    unsigned int VAO = 0;
    unsigned int VBO = 0;
    unsigned int vertexCount = 0;

public:
    explicit Mesh(const std::vector<float>& vertices);
    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    void draw() const;
};