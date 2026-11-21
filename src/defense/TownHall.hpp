// This is basically the tower maybe added for decoration purpose
// seriously dont know what this does
#pragma once

#include "Block.hpp"
#include "DefenseType.hpp"

namespace defense
{
    class TownHall : public Block {
        public:
        TownHall(float x, float y)
            : Block(64, DefenseType::townHall, x, y, 0, 0.f, 0.f) {}

        // TownHall does not attack.
        void attack(float) override {}
    };
} // namespace defense
