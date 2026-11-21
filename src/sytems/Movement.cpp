#include "Movement.hpp"
#include "Vector.hpp"

#include "../types/Pos.hpp"

namespace systems{
    void move(defense::Block *defender, attack::Block *attacker, float pace, float deltaTime){
        if(!defender || !attacker) return;

        const types::Pos from = attacker->getPosition();
        const types::Pos to = defender->getPosition();
        const float dist = systems::distance(from, to);

        // Already on top of the target; nothing to do.
        if(dist <= 0.0001f) return;

        types::Pos step = systems::scale(
            systems::unitVector(systems::directionVector(from, to)),
            pace * deltaTime);

        // Do not overshoot the target in a single frame.
        const float stepLength = systems::distance(step);
        if(stepLength > dist){
            step = systems::scale(step, dist / stepLength);
        }

        attacker->setPosition(from + step);
    }
}
