#pragma once

#include "../defense/Block.hpp"
#include "../attack/Block.hpp"

#include <cstdint>

namespace systems{
    // damage code will be written here
    void combatAttack(attack::Block *attacker, defense::Block *defender, std::int32_t damage);
    void combatDefense(attack::Block *attacker, defense::Block *defender, std::int32_t damage);
} // namespace systems
