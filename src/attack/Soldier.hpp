#pragma once

#include "Block.hpp"
#include "AttackType.hpp"

#include "../Core/GameObject.hpp"

// types
#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

// std
#include <cstdint>
#include <unordered_map>
#include <utility>

namespace attack{
    inline std::unordered_map<types::Levels, std::pair<std::uint32_t, std::uint32_t>> soldierMaps = {
        {types::Levels::Level1, {10, 10}}, // health, damage
        {types::Levels::Level2, {12, 14}},
        {types::Levels::Level3, {14, 17}},
        {types::Levels::Level4, {16, 21}},
        {types::Levels::Level5, {19, 22}}
    };
    class Soldier : protected Block, public GameObject {
        public:
        Soldier(types::Levels cannonType, float x, float y)
            : Block(12, soldierMaps[cannonType].first, AttackType::soldier, x, y, soldierMaps[cannonType].second), GameObject{x, y}{}
        
    };
}