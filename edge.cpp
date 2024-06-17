#include "edge.hpp"

bool Edge::isRoad(){
    if(owner == -1){
        return true;
    }
    return false;
}

void Edge::placeRoad(){
    owner = 1;
}

void Edge::setId(int edgeId){
    id = edgeId;
}

int Edge::getId() const{
    return id;
}

