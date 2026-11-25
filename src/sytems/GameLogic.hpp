// this basically like the validity check of the world
// like to see if one townhall exists


#pragma once

#include "../defense/Block.hpp"

namespace systems {
    class GameLogic{
        static bool isValidBase();
        static float damageCount();
    };
}