// have not added damage logic so far
// will add it once put it in the constructor
// have not implemented soldier code for the attack logic
// as the attack logic in that case will be a bit complex

#include "Block.hpp"

#include "../attack/Block.hpp"

#include "../sytems/Combat.hpp"
#include "../sytems/Intelligence.hpp"
#include "../sytems/Movement.hpp"
#include "../sytems/Vector.hpp"

// std
#include <stdexcept>

void defense::Block::healthLost(std::uint16_t damage){
    if(health == 0){
        isAttacking = false;
        return;
    } // had to make the block dissapear 
    // but aint doing graphics till now
    if(health < 0) throw std::runtime_error("Leaks in health");
    if(health - damage <= 0) setHealth(0);
    else setHealth(health - damage);
}

void defense::Block::attack(){
    // need to add range in such cases
    if(!isAttacking) target = systems::findClosestAttack(this);
    isAttacking = true;
    systems::combatDefense(target, this);
}