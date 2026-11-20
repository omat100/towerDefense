#pragma once

namespace attack{
    struct Pos{
        float x, y;
    };
    enum class AttackType{
        soldier,
        tank,
        balloon
    };
    enum class Levels{
        Level1,
        Level2,
        Level3,
        Level4,
        Level5
    };
}