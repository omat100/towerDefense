#pragma once

namespace types {
    struct Pos
    {
        float x, y;
    };
    Pos operator+(const Pos& a, const Pos&b){
        return Pos{a.x + b.x, b.y + a.y};
    }
}