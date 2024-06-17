#pragma once

#include <vector>
#include "vertex.hpp"
#include "edge.hpp"
#include "meshushe.hpp"

class Board
{
    private:
    std::vector<Vertex> listBoardVertex; // List of vertex on the board
    std::vector<Edge> listBoardEdge; // List of edge on the board

    public:
    Edge boardedge[72]; // All the edge
    Vertex boardVertex[54]; // All the vertex 
    Meshushe meshushe[19]; // All the meshushe 
    
    Board() : listBoardVertex(54), listBoardEdge(72){
        initialize();
        defineEdgeAndVertex();
    }
    void printBoard(); // Print the board
    void initialize(); // Initialize the board
    void defineEdgeAndVertex(); // Define the edge and vertex
    bool isVertexEmpty(int vertexIndex) const; // Check if the vertex is empty - so we can place here settlement or city
    bool isEdgeEmpth(int edgeIndex) const; // Check if the edge is empty - so we can place here road
    void placeSettlement(int vertexIndex); // Place the settlement on the board
    void placeCity(int vertexIndex); // Place the city o the board
    void placeRoad(int edgeIndex); // Place the road on the board
    void setVertex(int placeNum); // Set the vertex to the color of the player

    void setEdge(int placeNum); // Set the edge to the color of the player

};
