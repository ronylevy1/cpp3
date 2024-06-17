#pragma once
#include <string>
#include <vector>

class Edge{
    private:
        int id; // Every edge has a number
        std::string resourceType; // Every edge has a resource type

    public:
        std::vector<int> edge_neighbor_edge; // Each edge has neighbor edge
        std::vector<int> edge_neighbor_vertex; // Each edge is between 2 vertices
        int owner; // Each edge has owner. If the edge didnt have an owner, the owner will be -1. 

        bool isEmpty; // At the start of the game, all edges are empty. If you sit on them during the game, the sign changes

        bool isRoad(); // Can i buy the roud ?

        void placeRoad(); // Place a road

        void setId(int edgeId); // Set the id of the edge
        int getId() const; // Get the id of the edge

    Edge() {}
    Edge(int id){
        this->id = id;
    }
    
    Edge(int edgeId, const std::vector<int>& edgeNeighbors, const std::vector<int>& vertexNeighbors): 
        id(edgeId), edge_neighbor_edge(edgeNeighbors), edge_neighbor_vertex(vertexNeighbors), owner(-1) {
    }
};