// The main goal of this is to help player select a enemy for itself
// or the way round
// cause i dont know who is hero and who is villan

// currently for initial purposes 
// we will only consider one of them

// we need to create a player manager for this


#pragma once

// types
#include "../types/Pos.hpp"
#include "../types/GameObjects.hpp"

#include "../attack/Block.hpp"
#include "../defense/Block.hpp"

#include "Vector.hpp"

// std
#include <vector>
#include <stdexcept>
#include <limits>

namespace systems
{
    defense::Block *findClosestDefense(attack::Block *attacker);
    attack::Block *findClosestAttack(defense::Block *defender);
} // namespace systems