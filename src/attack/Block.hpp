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
            Pos position;
        
        protected:
            Block(float pace, std::uint16_t health, AttackType attackType, float x, float y)
                : pace{pace}, attackType{attackType}, health{health}, position{x, y} {}
            
            virtual void attack(std::uint16_t damage);
            virtual void healthLost(std::uint16_t damage);

            // void move(){} // have no logic for this will need to start with sfml to start with this
            // movement wont be handled by block

            // to be handled by system
            Pos getPosition() const { return position; }
            void setPosition(Pos position) { this->position = position; }

            int getHealth() const { return health; }
            void setHealth(int health) { this->health = health; }

            AttackType getAttackType() const { return attackType; }

            virtual ~Block() = default;
    };
}