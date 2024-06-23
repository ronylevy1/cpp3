// Roniki04@gmail.com

#include "vertex.hpp"

bool Vertex::buySettelment(const Vertex& vertex){
    if(vertex.numOfPoints == 0 || vertex.numOfPoints == 2){ // If the vertex has 0 or 2 points, you can't buy a settlement
        return false;
    }
    return true;
}

bool Vertex::buyCity(const Vertex& vertex){
    if(vertex.numOfPoints == 0 || vertex.numOfPoints == 1){ // If the vertex has 0 or 1 points, you can't buy a city
        return false;
    }
    return true;
}

bool Vertex::isSettelment() const{ 
    return whatPoint == 1; // If the vertex has a settlement, return true
}

bool Vertex::isCity() const{
    return whatPoint == 2; // If the vertex has a city, return true
}

void Vertex::placeSettlement(){
    whatPoint = 1; // Place a settlement
}

void Vertex::placeCity(){
    whatPoint = 2; // Place a city
}

std::string Vertex::getResourceType() const{
    return resourceType; // Get the resource type
}

void Vertex::setId(int vertexId){
    id = vertexId;
}

int Vertex::getId() const{
    return id;
}

