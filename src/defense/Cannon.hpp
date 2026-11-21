// cannon has damage and health values as well
// this will be given in pair format

#pragma once

#include "DefenseType.hpp"
#include "Block.hpp"

// types
#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

// std
#include <cstdint>
#include <unordered_map>
#include <utility>

namespace defense{
    inline constexpr float cannonRange = 180.f;
    inline constexpr float cannonAttackInterval = 0.8f;

    inline std::unordered_map<types::Levels, std::pair<std::uint32_t, std::uint32_t>> cannonMaps = {
        {types::Levels::Level1, {10, 10}}, // health, damage
        {types::Levels::Level2, {12, 14}},
        {types::Levels::Level3, {14, 17}},
        {types::Levels::Level4, {16, 21}},
        {types::Levels::Level5, {19, 22}}
    };

    class Cannon : public Block {
        public:
        Cannon(types::Levels cannonType, float x, float y)
            : Block(static_cast<int>(cannonMaps[cannonType].first),
                    DefenseType::cannon,
                    x, y,
                    static_cast<int>(cannonMaps[cannonType].second),
                    cannonRange,
                    cannonAttackInterval) {}
    };
}
