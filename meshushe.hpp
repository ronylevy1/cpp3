#pragma once
#include "vertex.hpp"

class Meshushe{
    public:
        Vertex vertex[6];
        int idMesh;
        std::string resourceType;
        
        Meshushe(int id, std::string resourceType, Vertex vertex[6]){
            this->idMesh = id;
            this->resourceType = resourceType;
            for(int i = 0; i < 6; i++){
                this->vertex[i] = vertex[i];
            }
        }
        Meshushe(){}
};