// This is the file where wall is defined
// a wall will be of a particular level 
// According to that level its health will be given

#pragma once

#include "DefenseType.hpp"
#include "Block.hpp"

// std
#include <unordered_map>
#include <cstdint>

namespace enemy{
    std::unordered_map<Levels, uint16_t> strength_health_map
     = {
        {Levels::Level1, 15},
        {Levels::Level2, 20},
        {Levels::Level3, 25},
        {Levels::Level4, 30},
        {Levels::Level5, 35},
     };

    class Wall : protected Block {
    public:
        Wall(Levels wallType)
        : Block(strength_health_map[wallType], DefenseType::wall) {}

        void attack() override {};
        void healthLost(int damage) override;

    };
}