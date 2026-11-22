#pragma once

#include "Data.hpp"
#include "../SFML/Renderer.hpp"

namespace sceneBuilder
{
    // This basically takes in the data 
    // and uses it somehow with renderer
    void sceneMaker(SceneData *data, Renderer &renderer);
} // namespace sceneBuilder
