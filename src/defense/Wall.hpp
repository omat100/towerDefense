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

    enum class WallType : std::uint8_t{
        Level1,
        Level2,
        Level3,
        Level4,
        Level5,
    };
    std::unordered_map<WallType, uint16_t> strength_health_map
     = {
        {Level1, 15},
        {Level2, 20},
        {Level3, 25},
        {Level4, 30},
        {Level5, 35},
     }

    class Wall : protected Block {
        Wall(WallType wallType)
         : Block(strength_health_map[wallType]) {}
    };
}