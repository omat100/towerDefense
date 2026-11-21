// Tower has damage and health values as well
// this will be given in pair format

#pragma once

#include "DefenseType.hpp"
#include "Block.hpp"

#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

// std
#include <cstdint>
#include <unordered_map>
#include <utility>

namespace defense{
    inline constexpr float towerRange = 150.f;
    inline constexpr float towerAttackInterval = 1.0f;

    inline std::unordered_map<types::Levels, std::pair<std::uint32_t, std::uint32_t>> towerMaps = {
        {types::Levels::Level1, {10, 12}}, // health, damage
        {types::Levels::Level2, {14, 14}},
        {types::Levels::Level3, {18, 17}},
        {types::Levels::Level4, {22, 18}},
        {types::Levels::Level5, {27, 20}}
    };

    class Tower : public Block {
        public:
        Tower(types::Levels towerType, float x, float y)
            : Block(static_cast<int>(towerMaps[towerType].first),
                    DefenseType::tower,
                    x, y,
                    static_cast<int>(towerMaps[towerType].second),
                    towerRange,
                    towerAttackInterval) {}
    };
}
