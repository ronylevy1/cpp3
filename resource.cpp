// Roniki04@gmail.com

#include <iostream>
#include <string>
#include "resource.hpp"

int Resource::getResourceAmount(const std::string& resourceType) const { 
    if (resourceType == "wood") {
        return wood;
    } else if (resourceType == "brick") {
        return brick;
    } else if (resourceType == "sheep") {
        return sheep;
    } else if (resourceType == "wheat") {
        return wheat;
    } else if (resourceType == "stone") {
        return stone;
    } else {
        std::cerr << "Unknown resource type: " << resourceType << std::endl;
        return 0;
    }
}

void Resource::incrementResource(const std::string& resourceType, int amount) {
    if (resourceType == "wood") {
        wood += amount;
    } else if (resourceType == "brick") {
        brick += amount;
    } else if (resourceType == "sheep") {
        sheep += amount;
    } else if (resourceType == "wheat") {
        wheat += amount;
    } else if (resourceType == "stone") {
        stone += amount;
    } else {
        std::cerr << "Unknown resource type: " << resourceType << std::endl;
    }
    std::cout << "Resource " << resourceType << " updated by " << amount << ". New amount: " << getResourceAmount(resourceType) << std::endl;
}
