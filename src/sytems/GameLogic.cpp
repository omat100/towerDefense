#include "GameLogic.hpp"
#include "../types/GameObjects.hpp"

#include "../defense/Block.hpp"

#include <algorithm>
#include <stdexcept>

bool systems::GameLogic::isValidBase(){
    int count = std::count_if(
        types::defenders.begin(), types::defenders.end(),
        [](defense::Block *defender){
            return defender->getDefenseType() == defense::DefenseType::townHall;
        }
    );
    if(count == 1) return true;
    throw std::logic_error("Town Hall number: " + count);
}

float systems::GameLogic::damageCount(){
    int count = std::count_if(
        types::defenders.begin(), types::defenders.end(),
        [](auto *defender){
            return defender->isAlive();
        }
    );
    if(count < 0) throw std::logic_error("Count less than zero");
    if(count > types::defenders.size()) throw std::logic_error("Count more than the defenders");
    return static_cast<float>(count)/types::defenders.size(); // float/size_t = float
}