#pragma once
#include "DefenseType.hpp"

namespace enemy {
    class Block{
        private:
            bool isAlive = true;
            DefenseType defenseType;

        protected:
            virtual void attack() = 0;
            DefenseType getDefenseType() const {return defenseType;}
    };
}