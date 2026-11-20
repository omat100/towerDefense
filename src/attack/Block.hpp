// This is the invader
// have not decided the side by which the player will play
// invader side or defense

#pragma once

#include "AttackType.hpp"

// types
#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

// std
#include <cstdint>

namespace attack {
    class Block{
        private:
            float pace;
            AttackType attackType;
            std::uint16_t health;
            types::Pos position;
            bool isAttacking = false;
            std::uint16_t damage;
        
        protected:
            Block(float pace, std::uint16_t health, AttackType attackType, float x, float y, std::uint16_t damage)
                : pace{pace}, attackType{attackType}, health{health}, position{x, y}, damage{damage} {}
            
            virtual void attack();
            
            // void move(){} // have no logic for this will need to start with sfml to start with this
            // movement wont be handled by block
            
            // to be handled by system
            
            AttackType getAttackType() const { return attackType; }
            
            virtual ~Block() = default;
            
        public:
            types::Pos getPosition() const { return position; }
            void setPosition(types::Pos position) { this->position = position; }
            
            bool getAttackStatus() const { return isAttacking; }
            void setAttackStatus(bool isAttacking) { this->isAttacking = isAttacking; }
            
            int getHealth() const { return health; }
            void setHealth(int health) { this->health = health; }

            std::uint16_t getDamage() const { return damage; }
            
            void healthLost(std::uint16_t damage);
        };
}