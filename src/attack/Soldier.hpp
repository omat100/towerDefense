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
    inline constexpr float soldierPace = 70.f;
    inline constexpr float soldierRange = 55.f;
    inline constexpr float soldierAttackInterval = 0.6f;

    inline std::unordered_map<types::Levels, std::pair<std::uint32_t, std::uint32_t>> soldierMaps = {
        {types::Levels::Level1, {10, 10}}, // health, damage
        {types::Levels::Level2, {12, 14}},
        {types::Levels::Level3, {14, 17}},
        {types::Levels::Level4, {16, 21}},
        {types::Levels::Level5, {19, 22}}
    };

    class Soldier : public Block {
        public:
        Soldier(types::Levels soldierType, float x, float y)
            : Block(soldierPace,
                    static_cast<int>(soldierMaps[soldierType].first),
                    AttackType::soldier,
                    x, y,
                    static_cast<int>(soldierMaps[soldierType].second),
                    soldierRange,
                    soldierAttackInterval) {}
    };
}
