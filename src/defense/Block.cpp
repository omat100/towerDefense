#include "Block.hpp"

// std
#include <stdexcept>

void enemy::Block::healthLost(std::uint16_t damage){
    if(getHealth() == 0) return; // had to make the block dissapear 
    // but aint doing graphics till now
    if(getHealth() < 0) throw std::runtime_error("Leaks in health");
    if(getHealth() - damage <= 0) setHealth(0);
    else setHealth(getHealth() - damage);
}

void enemy::Block::attack(std::uint16_t damage){
    // it makes me wonder
    // why dont dreams come true
}