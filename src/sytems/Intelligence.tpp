#include "../types/Pos.hpp"

template<typename From, typename To>
To* systems::findClosest(From *opponent){
    if(!opponent) return nullptr;

    const types::Pos aPos = opponent->getPosition();
    To *target = nullptr;
    float minDist = std::numeric_limits<float>::max();

    for(To *defender: types::defenders){ // this loop needs working
        if(!defender || !defender->isAlive()) continue;

        const float dist = systems::distance(aPos, defender->getPosition());
        if(dist < minDist){
            minDist = dist;
            target = defender;
        }
    }

    return target;
}