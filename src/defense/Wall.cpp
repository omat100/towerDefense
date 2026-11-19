#include "Wall.hpp"

#include <stdexcept>
void enemy::Wall::healthLost(int damage) {
    if(getHealth() == 0) return; // had to make the block dissapear 
    // but aint doing graphics till now
    if(getHealth() < 0) throw std::runtime_error("Leaks in health");
    if(getHealth() - damage <= 0) setHealth(0);
    else setHealth(getHealth() - damage);
}