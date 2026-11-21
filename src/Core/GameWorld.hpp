// This is the manager for attack and defense
#pragma once

// std
#include <memory>
#include <vector>

// defense
#include "../defense/Block.hpp"

// attack
#include "../attack/Block.hpp"

class GameWorld {
    public:
        // The intelligence system uses global indexes; one world owns them.
        GameWorld();
        ~GameWorld();

        // Registers the unit with the global target index and takes ownership.
        attack::Block *addAttack(std::unique_ptr<attack::Block> unit);
        defense::Block *addDefense(std::unique_ptr<defense::Block> unit);

        // Runs one simulation step, then removes dead units.
        void update(float deltaTime);
        void cleanup();

        bool hasAttackers() const { return !attacks.empty(); }
        bool hasDefenders() const { return !defenses.empty(); }

        const std::vector<std::unique_ptr<attack::Block>> &getAttacks() const { return attacks; }
        const std::vector<std::unique_ptr<defense::Block>> &getDefenses() const { return defenses; }

    private:
        std::vector<std::unique_ptr<attack::Block>> attacks;
        std::vector<std::unique_ptr<defense::Block>> defenses;
};
