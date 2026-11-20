#include "Intelligence.hpp"

defense::Block* Intelligence::findClosestDefense(attack::Block *attacker){
    const types::Pos aPos = attacker->getPosition();
    if(defenders.empty()) throw std::runtime_error("No defense left to attack");
    float minDist = std::numeric_limits<float>::max();
    defense::Block *target = defenders[0];
    for(defense::Block *defender: defenders){
        if(systems::distance(aPos, defender->getPosition()) < minDist){
            target = defender;
        }
    }
    return target;
}

attack::Block* Intelligence::findClosestAttack(defense::Block *defender){
    const types::Pos dPos = defender->getPosition();
    if(defenders.empty()) throw std::runtime_error("No attack left to defend");
    float minDist = std::numeric_limits<float>::max();
    attack::Block *target = attackers[0];
    for(attack::Block *attacker: attackers){
        if(systems::distance(dPos, attacker->getPosition()) < minDist){
            target = attacker;
        }
    }
    return target;
}