#pragma once

// std
#include <cstdint>

namespace defense{
    enum class DefenseType{
        wall = 0,
        cannon = 1,
        tower = 2,
        soldier = 3,
        townHall = 4
    };
    enum class Levels : std::uint8_t{
        Level1,
        Level2,
        Level3,
        Level4,
        Level5
    };
}