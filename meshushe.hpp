#pragma once
#include "vertex.hpp"

class Meshushe{
    public:
        Vertex vertex[6]; // The vertex of the meshushe
        int idMesh; // The id of the meshushe
        std::string resourceType; // The resource type of the meshushe

        Meshushe(int id, std::string resourceType, Vertex vertex[6]){
            this->idMesh = id;
            this->resourceType = resourceType;
            for(int i = 0; i < 6; i++){
                this->vertex[i] = vertex[i];
            }
        }
        Meshushe(){}
};