// Roniki04@gmail.com
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for rand()
#include "edge.hpp"
#include "vertex.hpp"
#include "board.hpp"


#pragma once
class Resource {
public:
    int wood = 0; 
    int brick = 0;
    int sheep = 0;
    int wheat = 0;
    int stone = 0;

    int getResourceAmount(const std::string& resourceType) const; // Get the num of a resource
    void incrementResource(const std::string& resourceType, int amount); // Increment the num of a resource
};
