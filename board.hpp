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
    int gameBoard[5][5];
    Edge boardedge[72]; // All the edgs at the start dont have an owner
    Vertex boardVertex[54]; // All the vertex at the start dont have an owner
    Meshushe meshushe[19]; // All the meshushe at the start dont have an owner
    
    Board() : listBoardVertex(54), listBoardEdge(72){
        initialize();
        defineEdgeAndVertex();
    }
    void printBoard();
    void initialize();
    void defineEdgeAndVertex();
    bool isVertexEmpty(int vertexIndex) const; // Check if the vertex is empty - so we can place here settlement or city
    bool isEdgeEmpth(int edgeIndex) const; // Check if the edge is empty - so we can place here road
    void placeSettlement(int vertexIndex); // Place the settlement on the board
    void placeCity(int vertexIndex); // Place the city o the board
    void placeRoad(int edgeIndex); // Place the road on the board
    void setPointState(int vertexIndex, std::string color); // Set the point state to the color of the player
    void setRoadState(int edgeIndex, std::string color); // Set the road state to the color of the player
    void setSettlementState(int vertexIndex, std::string color); // Set the settlement state to the color of the player
    void setCityState(int vertexIndex, std::string color); // Set the city state to the color of the player

    void setColor(int index, std::string color); // Set the color of the edge or the vertex

    void setVertex(int placeNum, std::string color); // Set the vertex to the color of the player
    void setVertex(int placeNum); // Set the vertex to the color of the player

    void setEdge(int placeNum); // Set the edge to the color of the player

};
