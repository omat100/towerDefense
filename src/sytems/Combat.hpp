#pragma once

#include "../defense/Block.hpp"
#include "../attack/Block.hpp"


namespace systems{
    // damage code will be written here
    void combatAttack(attack::Block *attacker, defense::Block *defender);
    void combatDefense(attack::Block *attacker, defense::Block *defender);
} // namespace systems
