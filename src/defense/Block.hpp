#pragma once

#include "DefenseType.hpp"

// types
#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

// std
#include <cstdint>

namespace defense {
    class Block{
        private:
            // bool isAlive = true;
            DefenseType defenseType;
            std::uint16_t health; // 0 - 65
            types::Pos position;
            bool isAttacking = false;

        protected:
            Block(std::uint16_t health, DefenseType defenseType, float x, float y)
                : health{health}, defenseType{defenseType}, position{x,y} {}
            
            virtual void attack(std::uint16_t damage);
            
            DefenseType getDefenseType() const {return defenseType;}
            
            virtual ~Block() = default;
            
            public:
            // to be handled by system
            types::Pos getPosition() const { return position; }
            void setPosition(types::Pos position) { this->position = position; }
            
            // for the combat and intelligence
            bool getAttackStatus() const { return isAttacking; }
            void setAttackStatus(bool isAttacking) { this->isAttacking = isAttacking; }
            
            std::int16_t getHealth() const { return health; }
            void setHealth(std::int16_t newHealth) { health = newHealth; }
            
            void healthLost(std::uint16_t damage);
        };
}