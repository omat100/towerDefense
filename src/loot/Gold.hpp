#pragma once

#include "Block.hpp"

#include <unordered_map>
#include <utility>

namespace loot
{
    inline const std::unordered_map<types::Levels, std::pair<int, int>> levelGoldMap = {
        {types::Levels::Level1, {50, 1000}}, // maxHealth, maxStorage
        {types::Levels::Level2, {60, 1200}},
        {types::Levels::Level3, {70, 1400}},
        {types::Levels::Level4, {80, 1800}},
        {types::Levels::Level5, {90, 2000}}
    };
    class Gold : public Block
    {
        private:
            float x, y;
            
        public:
            Gold(int currStorage, types::Levels level, float x, float y)
            : Block{LootType::Gold, levelGoldMap.at(level).second, levelGoldMap.at(level).first, currStorage,x, y}, x{x}, y{y} {};
    };
} // namespace loot
