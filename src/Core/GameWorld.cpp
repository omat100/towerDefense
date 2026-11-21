#include "GameWorld.hpp"

#include "../types/GameObjects.hpp"

// std
#include <algorithm>
#include <utility>

GameWorld::GameWorld(){
    // Start from a clean global index so no stale pointers survive a
    // previous world (or a previous test run).
    types::attackers.clear();
    types::defenders.clear();
}

GameWorld::~GameWorld(){
    types::attackers.clear();
    types::defenders.clear();
}

attack::Block *GameWorld::addAttack(std::unique_ptr<attack::Block> unit){
    if(!unit) return nullptr;

    attack::Block *raw = unit.get();
    attacks.push_back(std::move(unit));
    types::attackers.push_back(raw);
    return raw;
}

defense::Block *GameWorld::addDefense(std::unique_ptr<defense::Block> unit){
    if(!unit) return nullptr;

    defense::Block *raw = unit.get();
    defenses.push_back(std::move(unit));
    types::defenders.push_back(raw);
    return raw;
}

void GameWorld::update(float deltaTime){
    for(auto &unit: attacks){
        if(unit && unit->isAlive()) unit->update(deltaTime);
    }

    for(auto &unit: defenses){
        if(unit && unit->isAlive()) unit->update(deltaTime);
    }

    cleanup();
}

void GameWorld::cleanup(){
    // Clear target pointers before erasing anything so no unit keeps a
    // pointer to a dead unit.
    for(auto &unit: attacks){
        if(unit && unit->getTarget() && !unit->getTarget()->isAlive()){
            unit->clearTarget();
        }
    }

    for(auto &unit: defenses){
        if(unit && unit->getTarget() && !unit->getTarget()->isAlive()){
            unit->clearTarget();
        }
    }

    attacks.erase(
        std::remove_if(attacks.begin(), attacks.end(),
            [](const std::unique_ptr<attack::Block> &unit){
                return !unit || !unit->isAlive();
            }),
        attacks.end());

    defenses.erase(
        std::remove_if(defenses.begin(), defenses.end(),
            [](const std::unique_ptr<defense::Block> &unit){
                return !unit || !unit->isAlive();
            }),
        defenses.end());

    // Rebuild the global index used by the intelligence system.
    types::attackers.clear();
    for(auto &unit: attacks) types::attackers.push_back(unit.get());

    types::defenders.clear();
    for(auto &unit: defenses) types::defenders.push_back(unit.get());
}
