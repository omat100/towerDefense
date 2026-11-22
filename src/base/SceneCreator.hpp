#pragma once

#include "Data.hpp"

namespace sceneBuilder
{
    // This basically takes in the data 
    // and uses it somehow with renderer
    void sceneMaker(SceneData *data, sf::RenderWindow &window);
} // namespace sceneBuilder
