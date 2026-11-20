#pragma once

#include <vector>
#include "../attack/Block.hpp"
#include "../defense/Block.hpp"

namespace types {
    extern std::vector<attack::Block*> attackers;
    extern std::vector<defense::Block*> defenders;
}