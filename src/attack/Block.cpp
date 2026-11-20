#include "Block.hpp"

void attack::Block::healthLost(std::uint16_t damage){
    if(health == 0){
        isAttacking = false;
        return;
    }
    if(health - damage <= 0) setHealth(0);
    else setHealth(health - damage);
}
