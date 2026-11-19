// This is basically the tower maybe added for decoration purpose
// seriously dont know what this does
#pragma once

#include "Block.hpp"
#include "DefenseType.hpp"


namespace defense
{
    class Cannon : protected Block {
        public:
        Cannon()
            : Block(75, DefenseType::townHall){}
        
            void attack(uint16_t damage) override {};
    };
} // namespace defense
