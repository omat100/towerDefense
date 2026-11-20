#include "Combat.hpp"

void systems::combatAttack(attack::Block *attacker, defense::Block *defender){
    if(!defender->getHealth()) attacker->setAttackStatus(false);
    else{
        attacker->setAttackStatus(true);
        defender->healthLost(attacker->getDamage());
    }
}

void systems::combatDefense(attack::Block *attacker, defense::Block *defender){
    if(!attacker->getHealth()) defender->setAttackStatus(false);
    else{
        defender->setAttackStatus(true);
        attacker->healthLost(defender->getDamage());
    }
}