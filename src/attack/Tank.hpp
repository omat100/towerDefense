#pragma once

#include "Block.hpp"
#include "AttackType.hpp"

// types
#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

// std
#include <cstdint>
#include <unordered_map>
#include <utility>

namespace attack{
    inline constexpr float tankPace = 45.f;
    inline constexpr float tankRange = 60.f;
    inline constexpr float tankAttackInterval = 0.9f;

    inline std::unordered_map<types::Levels, std::pair<std::uint32_t, std::uint32_t>> tankMaps = {
        {types::Levels::Level1, {10, 10}}, // health, damage
        {types::Levels::Level2, {12, 14}},
        {types::Levels::Level3, {14, 17}},
        {types::Levels::Level4, {16, 21}},
        {types::Levels::Level5, {19, 22}}
    };

    class Tank : public Block {
        public:
        Tank(types::Levels tankType, float x, float y)
            : Block(tankPace,
                    static_cast<int>(tankMaps[tankType].first),
                    AttackType::tank,
                    x, y,
                    static_cast<int>(tankMaps[tankType].second),
                    tankRange,
                    tankAttackInterval) {}
    };
}
