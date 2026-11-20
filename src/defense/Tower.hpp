// Tower has damage and health values as well
// this will be given in pair format

#pragma once

#include "DefenseType.hpp"
#include "Block.hpp"

#include "../Core/GameObject.hpp"

#include "../types/Levels.hpp"

// std
#include <cstdint>
#include <unordered_map>
#include <utility>

namespace defense{
    inline std::unordered_map<types::Levels, std::pair<std::uint32_t, std::uint32_t>> towerMaps = {
        {types::Levels::Level1, {10, 12}}, // health, damage
        {types::Levels::Level2, {14, 14}},
        {types::Levels::Level3, {18, 17}},
        {types::Levels::Level4, {22, 18}},
        {types::Levels::Level5, {27, 20}}
    };
    class Tower : protected Block, public GameObject {
        public:
        Tower(types::Levels towerType, float x, float y)
            : Block(towerMaps[towerType].first, DefenseType::tower, x, y, towerMaps[towerType].second), GameObject{x, y} {}
        
    };
}