#include "Intelligence.hpp"

defense::Block* systems::findClosestDefense(attack::Block *attacker){
    const types::Pos aPos = attacker->getPosition();
    if(types::defenders.empty()) throw std::runtime_error("No defense left to attack");
    float minDist = std::numeric_limits<float>::max();
    defense::Block *target = types::defenders[0];
    for(defense::Block *defender: types::defenders){
        if(systems::distance(aPos, defender->getPosition()) < minDist){
            minDist = systems::distance(aPos, defender->getPosition());
            target = defender;
        }
    }
    return target;
}

attack::Block* systems::findClosestAttack(defense::Block *defender){
    const types::Pos dPos = defender->getPosition();
    if(types::defenders.empty()) throw std::runtime_error("No attack left to defend");
    float minDist = std::numeric_limits<float>::max();
    attack::Block *target = types::attackers[0];
    for(attack::Block *attacker: types::attackers){
        if(systems::distance(dPos, attacker->getPosition()) < minDist){
            minDist = systems::distance(dPos, attacker->getPosition());
            target = attacker;
        }
    }
    return target;
}