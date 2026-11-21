// This is the file where wall is defined
// a wall will be of a particular level
// According to that level its health will be given

#pragma once

#include "DefenseType.hpp"
#include "Block.hpp"

// std
#include <unordered_map>
#include <cstdint>

#include "../types/Levels.hpp"

namespace defense{
    inline std::unordered_map<types::Levels, std::uint16_t> strength_health_map
     = {
        {types::Levels::Level1, 15},
        {types::Levels::Level2, 20},
        {types::Levels::Level3, 25},
        {types::Levels::Level4, 30},
        {types::Levels::Level5, 35},
     };

    class Wall : public Block {
    public:
        Wall(types::Levels wallType, float x, float y)
        : Block(static_cast<int>(strength_health_map[wallType]),
                DefenseType::wall, x, y, 0, 0.f, 0.f) {}

        // Walls do not attack.
        void attack(float) override {}
    };
}
