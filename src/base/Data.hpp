#pragma once

#include "../defense/DefenseType.hpp"
#include "../types/Pos.hpp"

// std
#include <vector>
#include <string>

namespace sceneBuilder{
    struct Placement {
        defense::Block type;
        types::Pos positon;
    };

    struct SceneData {
        std::string userName;
        std::vector<Placement *> defenses;
    };
}