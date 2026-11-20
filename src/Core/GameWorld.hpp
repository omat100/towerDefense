// This is the manager for attack and defense
#pragma once

// std
#include <vector>

// defense
#include "../defense/Block.hpp"

// attack
#include "../attack/Block.hpp"

class GameWorld {
    public:
        std::vector<defense::Block*> collectionDefense;
        std::vector<attack::Block*> collectionAttack;
};