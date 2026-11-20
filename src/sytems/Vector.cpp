#include "Vector.hpp"

namespace systems{
    types::Pos directionVector(types::Pos start, types::Pos end){
        types::Pos result;
        result.x = (end.x - start.x);
        result.y = (end.y - start.y);
        return result;
    }
    float distance(types::Pos start, types::Pos end){
        float x2 = std::pow(end.x - start.x, 2);
        float y2 = std::pow(end.y - start.y, 2);
        return std::sqrtf(x2+y2);
    }
    float distance(types::Pos directionVector){
        return std::sqrtf(directionVector.x * directionVector.x + directionVector.y*directionVector.y);
    }
    types::Pos unitVector(types::Pos directionVector){
        return types::Pos{directionVector.x/distance(directionVector), directionVector.y/distance(directionVector)};
    }
    types::Pos scale(types::Pos vector, float scalar){
        return types::Pos{vector.x*scalar, vector.y*scalar};
    }
}