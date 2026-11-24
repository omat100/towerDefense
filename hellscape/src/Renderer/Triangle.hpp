#pragma once

class Triangle {
private:
    unsigned int VAO, VBO;

public:
    Triangle();
    ~Triangle();

    Triangle(const Triangle&) = delete;
    Triangle& operator=(const Triangle&) = delete;

    void draw() const;
};