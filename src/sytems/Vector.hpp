#pragma once

// //attack
// #include "../attack/Block.hpp"

// // defense
// #include "../defense/Block.hpp"

// types
#include "../types/Levels.hpp"
#include "../types/Pos.hpp"

// std
#include <cmath>

namespace systems
{
    types::Pos directionVector(types::Pos start, types::Pos end);
    float distance(types::Pos start, types::Pos end);
    float distance(types::Pos directionVector);
    types::Pos unitVector(types::Pos directionVector);
    types::Pos scale(types::Pos vector, float scalar);
} // namespace systems

