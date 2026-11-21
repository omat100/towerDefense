#include "Block.hpp"


// systems
#include "../sytems/Combat.hpp"
#include "../sytems/Intelligence.hpp"
#include "../sytems/Movement.hpp"


void attack::Block::healthLost(std::uint16_t damage){
    if(health == 0){
        isAttacking = false;
        return;
    }
    if(health - damage <= 0) setHealth(0);
    else setHealth(health - damage);
}

void attack::Block::attack(){
    if(!isAttacking || !target){
        target = systems::findClosestDefense(this);
        systems::move(target, this, pace);
    }
    else{
        isAttacking = true;
        systems::combatAttack(this, target);
    }
}
