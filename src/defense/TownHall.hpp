// This is basically the tower maybe added for decoration purpose
// seriously dont know what this does
#pragma once

#include "Block.hpp"
#include "DefenseType.hpp"
#include "../Core/GameObject.hpp"

namespace defense
{
    class TownHall : protected Block, public GameObject{
        public:
        TownHall(float x, float y)
            : Block(64, DefenseType::townHall, x, y), GameObject{x, y} {}
        
            void attack(uint16_t damage) override {};
    };
} // namespace defense
