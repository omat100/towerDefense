#include "Combat.hpp"

void systems::combatAttack(attack::Block *attacker, defense::Block *defender, std::int32_t damage){
    if(!defender->getHealth()) attacker->setAttackStatus(false);
    else{
        attacker->setAttackStatus(true);
        defender->healthLost(damage);
    }
}

void systems::combatDefense(attack::Block *attacker, defense::Block *defender, std::int32_t damage){
    if(!attacker->getHealth()) defender->setAttackStatus(false);
    else{
        defender->setAttackStatus(true);
        attacker->healthLost(damage);
    }
}