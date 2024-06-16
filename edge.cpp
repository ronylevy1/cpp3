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

void Edge::setColor(std::string color){
    this->color = color;
}

void Edge::setId(int edgeId){
    id = edgeId;
}

int Edge::getId() const{
    return id;
}

std::string Edge::getResourceType() const{
    return color;
}

std::string Edge::getColor() const{
    return color;
}