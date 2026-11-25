#include "Block.hpp"

#include "../defense/Block.hpp"

// systems
#include "../sytems/Combat.hpp"
#include "../sytems/Intelligence.hpp"
#include "../sytems/Movement.hpp"
#include "../sytems/Vector.hpp"

void attack::Block::healthLost(int damage){
    if(health <= 0){
        clearTarget();
        return;
    }

    health -= damage;
    if(health < 0) health = 0;

    if(health == 0) clearTarget();
}

void attack::Block::update(float deltaTime){
    if(!isAlive()) return;
    attack(deltaTime);
}

void attack::Block::attack(float deltaTime){
    if(!isAlive()) return;
    if(!target || !target->isAlive()){
        target = systems::findClosestDefense(this);
        attackTimer = 0.f;
    }
    if(!target){
        isAttacking = false;
        return;
    }
    const float dist = systems::distance(getPosition(), target->getPosition());
    if(dist > range){
        isAttacking = false;
        systems::move(target, this, pace, deltaTime);
        return;
    }
    isAttacking = true;
    attackTimer += deltaTime;
    if(attackTimer >= attackInterval){
        attackTimer = 0.f;
        systems::Combat::combat<attack::Block, defense::Block>(this, target);
    }
}
