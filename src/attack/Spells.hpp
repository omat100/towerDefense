#pragma once

#include "Block.hpp"
#include "AttackType.hpp"

#include "../defense/Block.hpp"

#include "../types/Pos.hpp"
#include "../types/Levels.hpp"

#include "../sytems/Intelligence.hpp"
#include "../sytems/Combat.hpp"

// std
#include <unordered_map>
#include <utility>
#include <cstdint>
#include <vector>

namespace attack
{
    inline std::unordered_map<types::Levels, std::pair<std::uint32_t, std::uint32_t>> spellMap = {
        {types::Levels::Level1, {10, 10}}, // damage, range
        {types::Levels::Level2, {12, 14}},
        {types::Levels::Level3, {14, 17}},
        {types::Levels::Level4, {16, 21}},
        {types::Levels::Level5, {19, 22}}
    };
    class Spells : public Block{
        private:
            types::Levels level;
        public:
            Spells(types::Levels level, float x, float y)
            : Block(0, 1, AttackType::spells, x, y, 0, 0, 0), level{level} {};


            // need to start adding levels
            void attack(float deltatime) override {
                std::vector<defense::Block *> targets = systems::findDefenseRadius(this, static_cast<float>(spellMap[level].second));
                for(defense::Block *defender : targets) systems::Combat::combatAttack(this, defender);
                setHealth(0); // make it dead after one time use
            }
            
            void healthLost(int damage) override {};
    };
} // namespace attack
