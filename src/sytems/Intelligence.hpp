// The main goal of this is to help player select a enemy for itself
// or the way round
// cause i dont know who is hero and who is villan

// currently for initial purposes 
// we will only consider one of them

// we need to create a player manager for this


#pragma once

// types
#include "../types/Pos.hpp"

#include "../attack/Block.hpp"
#include "../defense/Block.hpp"

#include "Vector.hpp"

// std
#include <vector>
#include <stdexcept>
#include <limits>

class Intelligence {
private:
    std::vector<attack::Block*>& attackers;
    std::vector<defense::Block*>& defenders;

public:
    Intelligence(
        std::vector<attack::Block*>& attackers,
        std::vector<defense::Block*>& defenders
    ) : attackers(attackers), defenders(defenders) {}

    defense::Block *findClosestDefense(attack::Block *attacker){
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

    attack::Block *findClosestAttack(defense::Block *defender){
        const types::Pos dPos = defender->getPosition();
        if(defenders.empty()) throw std::runtime_error("No defense left to attack");
        float minDist = std::numeric_limits<float>::max();
        attack::Block *target = attackers[0];
        for(attack::Block *attacker: attackers){
            if(systems::distance(dPos, attacker->getPosition()) < minDist){
                target = attacker;
            }
        }
        return target;
    }
};