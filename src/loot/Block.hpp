#pragma once

#include "../Core/GameObject.hpp"

#include "LootType.hpp"

namespace loot
{
    class Block : public GameObject
    {
        private:
            LootType type;
            int health;
            int maxHealth;
            int maxStorage;
            int currStorage;

        protected:
            Block(LootType type, int maxHealth, int maxStorage, int currStorage, float x, float y)
            : GameObject{x, y}, type{type}, health{maxHealth}, maxHealth{maxHealth},
            maxStorage{maxStorage}, currStorage{currStorage} {}

        public:
            void update(float deltaTime) override {};

            LootType getLootType() const { return type; }
            
            int getHealth() const { return health; }
            int getMaxHealth() const { return maxHealth; }
            void setHealth(int newHealth) { health = newHealth; }
            bool isAlive() const { return health > 0; }

            int getMaxStorage() const { return maxStorage; }
            int getCurrStorage() const { return currStorage; }
            void setCurrStorage(int currStorage) { this->currStorage = currStorage; }
    };
} // namespace loot
