// This is the invader
// have not decided the side by which the player will play
// invader side or defense

#pragma once

#include "AttackType.hpp"

// std
#include <cstdint>

namespace attack {
    class Block{
        private:
            float pace;
            AttackType attackType;
            std::uint16_t health;
        
        protected:
            Block(float pace, AttackType attackType, std::uint16_t health)
                : pace{pace}, attackType{attackType}, health{health} {}
            
            virtual void attack(std::uint16_t damage);
            virtual void healthLost(std::uint16_t damage);

            void move();

            int getHealth() const { return health; }
            void setHealth(int health) { this->health = health; }

            virtual ~Block() = default;
    };
}