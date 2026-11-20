// Tower has damage and health values as well
// this will be given in pair format

#pragma once

#include "DefenseType.hpp"
#include "Block.hpp"

#include "../Core/GameObject.hpp"

// std
#include <cstdint>
#include <unordered_map>
#include <utility>

namespace defense{
    inline std::unordered_map<Levels, std::pair<std::uint32_t, std::uint32_t>> maps = {
        {Levels::Level1, {10, 12}}, // health, damage
        {Levels::Level2, {14, 14}},
        {Levels::Level3, {18, 17}},
        {Levels::Level4, {22, 18}},
        {Levels::Level5, {27, 20}}
    };
    class Tower : protected Block, public GameObject {
        public:
        Tower(Levels towerType, float x, float y)
            : Block(maps[towerType].first, DefenseType::tower, x, y), GameObject{x, y} {}
        
    };
}