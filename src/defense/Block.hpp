#pragma once

#include "DefenseType.hpp"

// std
#include <cstdint>

namespace defense {
    class Block{
        private:
            // bool isAlive = true;
            DefenseType defenseType;
            std::uint16_t health; // 0 - 65

        protected:
            Block(std::uint16_t health, DefenseType defenseType)
                : health{health}, defenseType{defenseType} {}
            
            virtual void attack(std::uint16_t damage);
            virtual void healthLost(std::uint16_t damage);

            std::int16_t getHealth() const { return health; }
            void setHealth(std::int16_t newHealth) { health = newHealth; }
            DefenseType getDefenseType() const {return defenseType;}
            
            virtual ~Block() = default;
    };
}