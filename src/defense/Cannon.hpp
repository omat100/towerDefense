// cannon has damage and health values as well
// this will be given in pair format

#pragma once

#include "DefenseType.hpp"
#include "Block.hpp"

// std
#include <cstdint>
#include <unordered_map>
#include <utility>

namespace defense{
    std::unordered_map<Levels, std::pair<std::uint32_t, std::uint32_t>> maps = {
        {Levels::Level1, {10, 10}}, // health, damage
        {Levels::Level2, {12, 14}},
        {Levels::Level3, {14, 17}},
        {Levels::Level4, {16, 21}},
        {Levels::Level5, {19, 22}}
    };
    class Cannon : protected Block {
        public:
        Cannon(Levels cannonType)
            : Block(maps[cannonType].first, DefenseType::cannon){}
        
    };
}