#pragma once

#include "Block.hpp"
#include "AttackType.hpp"

// std
#include <cstdint>
#include <unordered_map>
#include <utility>

namespace attack{
    std::unordered_map<Levels, std::pair<std::uint32_t, std::uint32_t>> maps = {
        {Levels::Level1, {10, 10}}, // health, damage
        {Levels::Level2, {12, 14}},
        {Levels::Level3, {14, 17}},
        {Levels::Level4, {16, 21}},
        {Levels::Level5, {19, 22}}
    };
    class Tank : protected Block {
        public:
        Tank(Levels cannonType)
            : Block(12, maps[cannonType].first, AttackType::tank){}
        
    };
}