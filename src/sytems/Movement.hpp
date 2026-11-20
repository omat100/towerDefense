#pragma once

// attack
#include "../attack/Block.hpp"

// defense
#include "../defense/Block.hpp"

namespace systems
{
    // defense::Block *mDefend(attack::Block *attacker);
    // basically this is i am this attacker block 
    // i am this defensive block
    // This function will move the attack block closer to the defensive block
    void move(defense::Block *defender, attack::Block *attacker, int pace);
} // namespace systems
