#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for rand()
#include "edge.hpp"
#include "vertex.hpp"
#include "board.hpp"


#ifndef Resource_hpp
#define Resource_hpp
class Resource {
public:
    int wood = 0;
    int brick = 0;
    int sheep = 0;
    int wheat = 0;
    int stone = 0;

    int getResourceAmount(const std::string& resourceType) const;
    void incrementResource(const std::string& resourceType, int amount);


};

#endif // Resource_hpp

    // void incrementResource(const std::string& resourceType, int amount) {
    //     if (resourceType == "wood") {
    //         wood += amount;
    //     } else if (resourceType == "brick") {
    //         brick += amount;
    //     } else if (resourceType == "sheep") {
    //         sheep += amount;
    //     } else if (resourceType == "wheat") {
    //         wheat += amount;
    //     } else if (resourceType == "stone") {
    //         stone += amount;
    //     }
    // }

//     void Resources::incrementResource(const std::string& resourceType, int amount) {
//     if (resourceType == "wood") {
//         wood += amount;
//     } else if (resourceType == "brick") {
//         brick += amount;
//     } else if (resourceType == "sheep") {
//         sheep += amount;
//     } else if (resourceType == "wheat") {
//         wheat += amount;
//     } else if (resourceType == "stone") {
//         stone += amount;
//     } else {
//         std::cerr << "Unknown resource type: " << resourceType << std::endl;
//     }
//     std::cout << "Resource " << resourceType << " updated by " << amount << ". New amount: " << getResourceAmount(resourceType) << std::endl;
// }



//     int getResourceAmount(const std::string& resourceType) const {
//         if (resourceType == "wood") {
//             return wood;
//         } else if (resourceType == "brick") {
//             return brick;
//         } else if (resourceType == "sheep") {
//             return sheep;
//         } else if (resourceType == "wheat") {
//             return wheat;
//         } else if (resourceType == "stone") {
//             return stone;
//         } else {
//             return 0;
//         }
//     }

//     void setResourceAmount(const std::string& resourceType, int amount) {
//         if (resourceType == "wood") {
//             wood = amount;
//         } else if (resourceType == "brick") {
//             brick = amount;
//         } else if (resourceType == "sheep") {
//             sheep = amount;
//         } else if (resourceType == "wheat") {
//             wheat = amount;
//         } else if (resourceType == "stone") {
//             stone = amount;
//         }
//     }