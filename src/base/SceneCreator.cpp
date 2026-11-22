#include "SceneCreator.hpp"
#include "../SFML/Renderer.hpp"
#include "../defense/Block.hpp"

#include <iostream>

void sceneBuilder::sceneMaker(SceneData *data, Renderer &renderer){
    std::cout << data->userName << std::endl;
    for(Placement *position : data->defenses){
        if(!position) continue;
        renderer.drawGhost(position->type, position->positon, true);
    }
}
