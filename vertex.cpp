#include "vertex.hpp"

bool Vertex::buySettelment(const Vertex& vertex){
    if(vertex.numOfPoints == 0 || vertex.numOfPoints == 2){
        return false;
    }
    return true;
}

bool Vertex::buyCity(const Vertex& vertex){
    if(vertex.numOfPoints == 0 || vertex.numOfPoints == 1){
        return false;
    }
    return true;
}

bool Vertex::isSettelment() const{
    return whatPoint == 1;
}

bool Vertex::isCity() const{
    return whatPoint == 2;
}

void Vertex::placeSettlement(){
    whatPoint = 1;
}

void Vertex::placeCity(){
    whatPoint = 2;
}

std::string Vertex::getResourceType() const{
    return resourceType;
}


void Vertex::setId(int vertexId){
    id = vertexId;
}

int Vertex::getId() const{
    return id;
}

