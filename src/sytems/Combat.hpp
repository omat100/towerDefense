#pragma once

#include "../defense/Block.hpp"
#include "../attack/Block.hpp"


namespace systems{
    // damage code will be written here
    class Combat{
        public:
        static void combatAttack(attack::Block *attacker, defense::Block *defender);
        static void combatDefense(attack::Block *attacker, defense::Block *defender);
        template <typename From, typename To>
        static void combat(From *attacker, To *defender);
    };
} // namespace systems

#include "Combat.tpp"
