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
    inline constexpr float balloonPace = 90.f;
    inline constexpr float balloonRange = 65.f;
    inline constexpr float balloonAttackInterval = 0.7f;

    inline std::unordered_map<types::Levels, std::pair<std::uint32_t, std::uint32_t>> balloonMaps = {
        {types::Levels::Level1, {10, 10}}, // health, damage
        {types::Levels::Level2, {12, 14}},
        {types::Levels::Level3, {14, 17}},
        {types::Levels::Level4, {16, 21}},
        {types::Levels::Level5, {19, 22}}
    };

    class Balloon : public Block {
        public:
        Balloon(types::Levels balloonType, float x, float y)
            : Block(balloonPace,
                    static_cast<int>(balloonMaps[balloonType].first),
                    AttackType::balloon,
                    x, y,
                    static_cast<int>(balloonMaps[balloonType].second),
                    balloonRange,
                    balloonAttackInterval) {}
    };
}
