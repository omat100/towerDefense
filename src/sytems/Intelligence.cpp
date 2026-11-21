#include "Intelligence.hpp"

defense::Block* systems::findClosestDefense(attack::Block *attacker){
    if(!attacker) return nullptr;

    const types::Pos aPos = attacker->getPosition();
    defense::Block *target = nullptr;
    float minDist = std::numeric_limits<float>::max();

    for(defense::Block *defender: types::defenders){
        if(!defender || !defender->isAlive()) continue;

        const float dist = systems::distance(aPos, defender->getPosition());
        if(dist < minDist){
            minDist = dist;
            target = defender;
        }
    }

    return target;
}

attack::Block* systems::findClosestAttack(defense::Block *defender){
    if(!defender) return nullptr;

    const types::Pos dPos = defender->getPosition();
    attack::Block *target = nullptr;
    float minDist = std::numeric_limits<float>::max();

    for(attack::Block *attacker: types::attackers){
        if(!attacker || !attacker->isAlive()) continue;

        const float dist = systems::distance(dPos, attacker->getPosition());
        if(dist < minDist){
            minDist = dist;
            target = attacker;
        }
    }
    
    return target;
}

std::vector<defense::Block*> systems::findDefenseRadius(attack::Block *attacker, float radius){
    if(!attacker) return {};
    
    std::vector<defense::Block*> allTargets;
    
    const types::Pos aPos = attacker->getPosition();
    for(defense::Block *defender : types::defenders){
        if(!defender || !defender->isAlive()) continue;
        
        const float dist = systems::distance(aPos, defender->getPosition());
        if(dist <= radius) allTargets.push_back(defender);
    }
    return allTargets;
}


std::vector<attack::Block*> systems::findDefenseRadius(defense::Block *defender, float radius){
    if(!defender) return {};
    
    std::vector<attack::Block*> allTargets;
    
    const types::Pos dPos = defender->getPosition();
    for(attack::Block *attacker : types::attackers){
        if(!attacker || !attacker->isAlive()) continue;
        
        const float dist = systems::distance(dPos, attacker->getPosition());
        if(dist <= radius) allTargets.push_back(attacker);
    }
    return allTargets;
}
