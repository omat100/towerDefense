#pragma once

#include "../defense/Block.hpp"
#include "../types/Pos.hpp"

#include <memory>

// std
#include <vector>
#include <string>

namespace sceneBuilder{
    struct Placement {
        std::unique_ptr<defense::Block> type;
        types::Pos positon;
    };

    struct SceneData {
        std::string userName;
        std::vector<Placement *> defenses;
    };
}