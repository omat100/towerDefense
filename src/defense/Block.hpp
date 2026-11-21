#pragma once

#include "DefenseType.hpp"

// types
#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

#include "../Core/GameObject.hpp"

// forward declaration to avoid a circular include
namespace attack { class Block; }

// std
#include <cstdint>

namespace defense {
    class Block : public GameObject {
        private:
            DefenseType defenseType;
            int health;
            int maxHealth;
            int damage;
            float range;
            float attackInterval;
            float attackTimer = 0.f;
            bool isAttacking = false;
            attack::Block *target = nullptr;

        protected:
            Block(int health, DefenseType defenseType, float x, float y, int damage,
                  float range, float attackInterval)
                : GameObject{x, y}, defenseType{defenseType}, health{health},
                  maxHealth{health}, damage{damage}, range{range},
                  attackInterval{attackInterval} {}

            virtual void attack(float deltaTime);

        public:
            ~Block() override = default;

            // Driven by GameWorld every frame.
            void update(float deltaTime) override;

            DefenseType getDefenseType() const { return defenseType; }

            int getHealth() const { return health; }
            int getMaxHealth() const { return maxHealth; }
            void setHealth(int newHealth) { health = newHealth; }
            bool isAlive() const { return health > 0; }

            int getDamage() const { return damage; }
            float getRange() const { return range; }

            // for the combat and intelligence
            bool getAttackStatus() const { return isAttacking; }
            void setAttackStatus(bool status) { isAttacking = status; }

            attack::Block *getTarget() const { return target; }
            void setTarget(attack::Block *newTarget) { target = newTarget; }
            void clearTarget() { target = nullptr; isAttacking = false; }

            void healthLost(int damage);
        };
}
