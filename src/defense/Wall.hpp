// This is the file where wall is defined
// a wall will be of a particular level 
// According to that level its health will be given

#pragma once

#include "DefenseType.hpp"
#include "Block.hpp"
#include "../Core/GameObject.hpp"

// std
#include <unordered_map>
#include <cstdint>

#include "../types/Levels.hpp"

namespace defense{
    inline std::unordered_map<types::Levels, uint16_t> strength_health_map
     = {
        {types::Levels::Level1, 15},
        {types::Levels::Level2, 20},
        {types::Levels::Level3, 25},
        {types::Levels::Level4, 30},
        {types::Levels::Level5, 35},
     };

    class Wall : protected Block, public GameObject {
    public:
        Wall(types::Levels wallType, float x, float y)
        : Block(strength_health_map[wallType], DefenseType::wall, x, y, 0), GameObject(x,y) {}

        void attack() override {};
        void update(float deltaTime) override {
            // Wall-specific update logic
        }
    };
}