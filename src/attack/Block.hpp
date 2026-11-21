// This is the invader
// have not decided the side by which the player will play
// invader side or defense

#pragma once

#include "AttackType.hpp"

// types
#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

#include "../Core/GameObject.hpp"

// forward declaration to avoid a circular include
namespace defense { class Block; }

// std
#include <cstdint>

namespace attack {
    class Block : public GameObject {
        private:
            float pace;          // pixels per second
            AttackType attackType;
            int health;
            int maxHealth;
            int damage;
            float range;
            float attackInterval;
            float attackTimer = 0.f;
            bool isAttacking = false;
            defense::Block *target = nullptr;

        protected:
            Block(float pace, int health, AttackType attackType, float x, float y,
                  int damage, float range, float attackInterval)
                : GameObject{x, y}, pace{pace}, attackType{attackType}, health{health},
                  maxHealth{health}, damage{damage}, range{range},
                  attackInterval{attackInterval} {}

            virtual void attack(float deltaTime);

        public:
            ~Block() override = default;

            // Driven by GameWorld every frame.
            void update(float deltaTime) override;

            AttackType getAttackType() const { return attackType; }

            int getHealth() const { return health; }
            int getMaxHealth() const { return maxHealth; }
            void setHealth(int newHealth) { health = newHealth; }
            bool isAlive() const { return health > 0; }

            int getDamage() const { return damage; }
            float getPace() const { return pace; }
            float getRange() const { return range; }

            bool getAttackStatus() const { return isAttacking; }
            void setAttackStatus(bool status) { isAttacking = status; }

            defense::Block *getTarget() const { return target; }
            void setTarget(defense::Block *newTarget) { target = newTarget; }
            void clearTarget() { target = nullptr; isAttacking = false; }

            void healthLost(int damage);
        };
}
