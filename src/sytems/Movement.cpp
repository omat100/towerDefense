#include "Movement.hpp"
#include "Vector.hpp"

#include "../types/Pos.hpp"

namespace systems{
    void move(defense::Block *defender, attack::Block *attacker, int pace){
        if(attacker->getAttackStatus()) return;
        types::Pos unitVector = systems::unitVector(systems::directionVector(defender->getPosition(), attacker->getPosition()));
        unitVector = systems::scale(unitVector, pace);
        attacker->setPosition(attacker->getPosition() + unitVector);
    }
}