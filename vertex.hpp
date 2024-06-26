// Roniki04@gmail.com
#pragma once
#include <string>
#include <vector>

class Vertex{
    private:
      int whatPoint = 0; // If 0 - empth. if 1 - settlement. if 2 - city
      std::string resourceType; // The resource type of the vertex
      int id; // Id of the vertex

    public:
        int numOfPoints; // Each vertex can have between 0 and 2 points
        std::vector<int> vertex_neighbor_vertex; // Each vertex has neighbor vertex
        std::vector<int> vertex_neighbor_edge; // Each edge is between 2 vertices
        bool isEmpty; // At the start of the game, all vertices are empty. If you sit on them during the game, the sign changes
        int owner; // Each vertex has owner. If the vertex didnt have an owner, the owner will be -1. 

        bool buySettelment(const Vertex& vertex); // Can i buy the settelment ?
        bool buyCity(const Vertex& vertex); // Can i buy the city ?

        bool isSettelment() const; // Is there is a settlement ?
        bool isCity() const; // Is there is a city ?
        
        void placeSettlement(); // Place a settlement
        void placeCity(); // Place a city

        void setId(int vertexId); // Set the id of the vertex
        int getId() const; // Get the id of the vertex

        std::string getResourceType() const; // Get the resource type
        
        Vertex() {}
        Vertex(int value){
            id = value;
        }
};