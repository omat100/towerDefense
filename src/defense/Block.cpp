#include "Block.hpp"

#include "../attack/Block.hpp"

#include "../sytems/Combat.hpp"
#include "../sytems/Intelligence.hpp"
#include "../sytems/Vector.hpp"

void defense::Block::healthLost(int damage){
    if(health <= 0){
        clearTarget();
        return;
    }

    health -= damage;
    if(health < 0) health = 0;

    if(health == 0) clearTarget();
}

void defense::Block::update(float deltaTime){
    if(!isAlive()) return;
    attack(deltaTime);
}

void defense::Block::attack(float deltaTime){
    if(!isAlive()) return;

    // Acquire a new target when we have none, or when the old one died.
    if(!target || !target->isAlive()){
        target = systems::findClosestAttack(this);
        attackTimer = 0.f;
    }

    if(!target){
        isAttacking = false;
        return;
    }

    const float dist = systems::distance(getPosition(), target->getPosition());

    // Defenses do not move; they only fire while the target is in range.
    if(range <= 0.f || dist > range){
        isAttacking = false;
        return;
    }

    isAttacking = true;
    attackTimer += deltaTime;
    if(attackTimer >= attackInterval){
        attackTimer = 0.f;
        systems::combatDefense(target, this);
    }
}
