#include "Movement.hpp"
#include "Vector.hpp"

#include "../types/Pos.hpp"

namespace systems{
    void move(defense::Block *defender, attack::Block *attacker, int pace){
        if(attacker->getAttackStatus()) return;
        types::Pos moveVector = systems::unitVector(systems::directionVector(attacker->getPosition(), defender->getPosition()));
        moveVector = systems::scale(moveVector, pace);
        attacker->setPosition(attacker->getPosition() + moveVector);
    }
}