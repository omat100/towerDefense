#include "Combat.hpp"

void systems::Combat::combatAttack(attack::Block *attacker, defense::Block *defender){
    if(!attacker || !defender) return;

    if(!attacker->isAlive() || !defender->isAlive()){
        attacker->clearTarget();
        return;
    }

    defender->healthLost(attacker->getDamage());

    // The defender died: drop the stale target so the attacker retargets.
    if(!defender->isAlive()){
        attacker->clearTarget();
    }
}

void systems::Combat::combatDefense(attack::Block *attacker, defense::Block *defender){
    if(!attacker || !defender) return;

    if(!attacker->isAlive() || !defender->isAlive()){
        defender->clearTarget();
        return;
    }

    attacker->healthLost(defender->getDamage());

    // The attacker died: drop the stale target so the defense retargets.
    if(!attacker->isAlive()){
        defender->clearTarget();
    }
}
