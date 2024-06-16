#include <vector>
#include <iostream>
#include <string>
#include <cstdlib> // for rand()
#include <algorithm> // for std::find
#include "player.hpp"
#include "edge.hpp"
#include "vertex.hpp"
#include "board.hpp"
#include "resource.hpp"
#include "meshushe.hpp"



void Player::rollDice(std::vector<Player>& players, Board& board){
    int rolledNumber = (rand() % 6 + 1) + (rand() % 6 + 1); // Sum of two roll dice 
    std::cout << "Rolled number: " << rolledNumber << std::endl;

    // Go over all the vertex
    for (int i = 0; i < 19; ++i) { 
        if (board.meshushe[i].idMesh == rolledNumber) {
            for (Player& player : players) { // Go over all the player in the list player
                
                for (int settlement : player.settelmentBuy) { // Go over all the settelment that the specific player buy
                   std::cout << "check4" << std::endl;
                    if (settlement == i) { // If the settlement is with the same number of the number that on the square
                        //player.resources += 1; // The player get one card of the resource
                        std::string resourceType = board.boardVertex[i].getResourceType();
                        if (resourceType == "wood") {
                            player.resources.wood += 1;
                        } else if (resourceType == "brick") {
                            player.resources.brick += 1;
                        } else if (resourceType == "sheep") {
                            player.resources.sheep += 1;
                        } else if (resourceType == "wheat") {
                            player.resources.wheat += 1;
                        } else if (resourceType == "stone") {
                            player.resources.stone += 1;
                        }
                        std::cout << "You have add 1 more resource of the type :" << resourceType << std::endl;
                    }
                }
                for (int city : player.cityBuy) { // Go over all the city that the specific player buy
                    if (city == i) { // If the city is with the same number of the number that on the square
                       // player.resources.push_back(2); // Increment player's points for city
                        std::string resourceType = board.boardVertex[i].getResourceType();
                        if (resourceType == "wood") {
                            player.resources.wood += 2;
                        } else if (resourceType == "brick") {
                            player.resources.brick += 2;
                        } else if (resourceType == "sheep") {
                            player.resources.sheep += 2;
                        } else if (resourceType == "wheat") {
                            player.resources.wheat += 2;
                        } else if (resourceType == "stone") {
                            player.resources.stone += 2;
                        }
                        std::cout << "You have add 2 more resource of the type :" << resourceType << std::endl;
                    }
                }
            }
        }
    }
}



// void Player::addResources(std::string resourceType, int amount) {
//     if (resourceType == "wood") {
//         resources.wood += amount;
//         std::cout << "Added " << amount << " of " << resourceType << " to " << playerName << std::endl;
//     } else if (resourceType == "brick") {
//         resources.brick += amount;
//         std::cout << "Added " << amount << " of " << resourceType << " to " << playerName << std::endl;
//     } else if (resourceType == "sheep") {
//         resources.sheep += amount;
//         std::cout << "Added " << amount << " of " << resourceType << " to " << playerName << std::endl;
//     } else if (resourceType == "wheat") {
//         resources.wheat += amount;
//         std::cout << "Added " << amount << " of " << resourceType << " to " << playerName << std::endl;
//     } else if (resourceType == "stone") {
//         resources.stone += amount;
//         std::cout << "Added " << amount << " of " << resourceType << " to " << playerName << std::endl;
//     }    
// }



// void Player::rollDice(std::vector<Player>& players, Board& board) {
//     int rolledNumber = (rand() % 6 + 1) + (rand() % 6 + 1); // Sum of two rolled dice
//     std::cout << "Rolled number: " << rolledNumber << std::endl;

//     // Go over all the vertices
//     for (int i = 0; i < 19; ++i) { 
//         std::cout << "check1" << std::endl;
//         if (board.meshushe[i].id == rolledNumber) {
//             std::cout << "check2" << std::endl;
//             for (Player& player : players) { // Go over all the players in the list 
//                 std::cout << "check3" << std::endl;
//                 for (int settlement : player.settelmentBuy) { // Go over all the settlements that the specific player bought
//                     if (settlement == i) { // If the settlement is with the same number as the number on the square
//                         std::string resourceType = board.meshushe[i].resourceType;
//                         player.addResources(resourceType, 1);
//                         std::cout << player.getPlayerName() << " has added 1 more resource of the type: " << resourceType << std::endl;
//                     }
//                 }
//                 for (int city : player.cityBuy) { // Go over all the cities that the specific player bought
//                     if (city == i) { // If the city is with the same number as the number on the square
//                         std::string resourceType = board.meshushe[i].resourceType;
//                         player.addResources(resourceType, 2);
//                         std::cout << player.getPlayerName() << " has added 2 more resources of the type: " << resourceType << std::endl;
//                     }
//                 }
//             }
//         }
//     }
// }





// TODO
void Player::endTurn(){
    // אם השתמש בקלף פיתוח - התור נגמר
}

void Player::trade(Player& tradeWith, std::string resourceGive, int amountGive, std::string resourceGet, int amountGet) {
    if (this->resources.getResourceAmount(resourceGive) >= amountGive && tradeWith.resources.getResourceAmount(resourceGet) >= amountGet) {
        this->resources.incrementResource(resourceGive, -amountGive);
        tradeWith.resources.incrementResource(resourceGet, -amountGet);
        this->resources.incrementResource(resourceGet, amountGet);
        tradeWith.resources.incrementResource(resourceGive, amountGive);
        std::cout << "The trade was succses" << std::endl;
    } else {
        std::cout << "There is no enough resource" << std::endl;
    }
}



void Player::buyDevelopmentCard(){
    resources.wheat -= 1;
    resources.sheep -= 1;
    resources.stone -= 1;

    std::cout << playerName << " buy a development card" << std::endl;
}

void Player::printPoints(){
    std::cout << "The num of points " << playerName << " have is : " << pointsOfPlayer << std::endl;
}

void Player::throwHalf(std::vector<int> cardsBuy){
    int num = cardsBuy.size() / 2;
    for(int i = 0; i < num; i++){
        cardsBuy.pop_back();
    }

    std::cout << playerName << "have throw half of the cards" << std::endl;
}

std::string Player::getPlayerName() const {
    return playerName;
}

int Player::getPointsOfPlayer() const {
    return pointsOfPlayer;
}

std::string Player::getColor() const {
    return playerName;
}

std::vector<Vertex> Player::placeSettlement(Board* board, int index){ //not good
    board->setVertex(index); // Set the vertex as a settlement
    settelmentBuy.push_back(index); // Add the settlement to the list of settlements
    pointsOfPlayer += 1; // Add a point to the player
    resources.brick -= 1; // Deduct the required resources for placing a settlement
    resources.wood -= 1;
    resources.sheep -= 1;
    resources.wheat -= 1;
    // board.
    std::cout << playerName << " have placed a settlement on vertex " << index << std::endl;
    return std::vector<Vertex>();
}

std::vector<Vertex> Player::placeCity(Board& board, int index){
    auto it = std::find(settelmentBuy.begin(), settelmentBuy.end(), index); // Check if the vertex is a settlement
    if (it == settelmentBuy.end()) { // If the vertex is not a settlement
        std::cout << "You can place a city only on a settlement" << std::endl;
        return std::vector<Vertex>(); 
    }

    board.setVertex(index); // Set the vertex as a city
    cityBuy.push_back(index); // Add the city to the list of cities
    pointsOfPlayer += 1; // Add a point to the player
    resources.wheat -= 2;
    resources.stone -= 3;
    std::cout << playerName << " have placed a city on vertex " << index << std::endl;
    return std::vector<Vertex>();
}

std::vector<Edge> Player::placeRoad(Board& board, int index){
    board.setEdge(index); // Set the edge as a road
    resources.brick -= 1; // Deduct the required resources for placing a settlement
    resources.wood -= 1;
    std::cout << playerName << " have placed a road on edge " << index << std::endl;
    return std::vector<Edge>();
}







// void Player::trade(Player& tradeWith, std::string resourceGive, int amountGive, std::string resourceGet, int amountGet) {
//     // Check if the player has enough resources to give
//     if ((resourceGive == "wood" && this->resources.wood < amountGive) ||
//         (resourceGive == "brick" && this->resources.brick < amountGive) ||
//         (resourceGive == "sheep" && this->resources.sheep < amountGive) ||
//         (resourceGive == "wheat" && this->resources.wheat < amountGive) ||
//         (resourceGive == "stone" && this->resources.stone < amountGive)) {
//         std::cout << "You don't have enough resources to trade" << std::endl;
//         return;
//     }

//     // Check if the other player has enough resources to give
//     if ((resourceGet == "wood" && tradeWith.resources.wood < amountGet) ||
//         (resourceGet == "brick" && tradeWith.resources.brick < amountGet) ||
//         (resourceGet == "sheep" && tradeWith.resources.sheep < amountGet) ||
//         (resourceGet == "wheat" && tradeWith.resources.wheat < amountGet) ||
//         (resourceGet == "stone" && tradeWith.resources.stone < amountGet)) {
//         std::cout << "The other player doesn't have enough resources to trade" << std::endl;
//         return;
//     }

//     // Execute the trade: deduct the resources from the current player and add to the other player
//     if (resourceGive == "wood") this->resources.wood -= amountGive;
//     if (resourceGive == "brick") this->resources.brick -= amountGive;
//     if (resourceGive == "sheep") this->resources.sheep -= amountGive;
//     if (resourceGive == "wheat") this->resources.wheat -= amountGive;
//     if (resourceGive == "stone") this->resources.stone -= amountGive;

//     if (resourceGet == "wood") this->resources.wood += amountGet;
//     if (resourceGet == "brick") this->resources.brick += amountGet;
//     if (resourceGet == "sheep") this->resources.sheep += amountGet;
//     if (resourceGet == "wheat") this->resources.wheat += amountGet;
//     if (resourceGet == "stone") this->resources.stone += amountGet;

//     // Execute the trade for the other player: add the resources from the current player and deduct from the other player
//     if (resourceGive == "wood") tradeWith.resources.wood += amountGive;
//     if (resourceGive == "brick") tradeWith.resources.brick += amountGive;
//     if (resourceGive == "sheep") tradeWith.resources.sheep += amountGive;
//     if (resourceGive == "wheat") tradeWith.resources.wheat += amountGive;
//     if (resourceGive == "stone") tradeWith.resources.stone += amountGive;

//     if (resourceGet == "wood") tradeWith.resources.wood -= amountGet;
//     if (resourceGet == "brick") tradeWith.resources.brick -= amountGet;
//     if (resourceGet == "sheep") tradeWith.resources.sheep -= amountGet;
//     if (resourceGet == "wheat") tradeWith.resources.wheat -= amountGet;
//     if (resourceGet == "stone") tradeWith.resources.stone -= amountGet;

//     std::cout << "Trade was successful" << std::endl;
// }

// void Player::trade(Player& tradeWith, std::string resourceGive, int amountGive, std::string resourceGet, int amountGet) {
//     // Check if the player has enough resources to give
//     if ((resourceGive == "wood" && this->resources.wood < amountGive) ||
//         (resourceGive == "brick" && this->resources.brick < amountGive) ||
//         (resourceGive == "sheep" && this->resources.sheep < amountGive) ||
//         (resourceGive == "wheat" && this->resources.wheat < amountGive) ||
//         (resourceGive == "stone" && this->resources.stone < amountGive)) {
//         std::cout << "You don't have enough resources to trade" << std::endl;
//         return;
//     }

//     // Check if the other player has enough resources to give
//     if ((resourceGet == "wood" && tradeWith.resources.wood < amountGet) ||
//         (resourceGet == "brick" && tradeWith.resources.brick < amountGet) ||
//         (resourceGet == "sheep" && tradeWith.resources.sheep < amountGet) ||
//         (resourceGet == "wheat" && tradeWith.resources.wheat < amountGet) ||
//         (resourceGet == "stone" && tradeWith.resources.stone < amountGet)) {
//         std::cout << "The other player doesn't have enough resources to trade" << std::endl;
//         return;
//     }

//     // Execute the trade only if both players have enough resources
//     if ((resourceGive == "wood") this->resources.wood >= amountGive &&
//         (resourceGive == "brick") this->resources.brick >= amountGive &&
//         (resourceGive == "sheep") this->resources.sheep >= amountGive &&
//         (resourceGive == "wheat") this->resources.wheat >= amountGive &&
//         (resourceGive == "stone") this->resources.stone >= amountGive &&
//         (resourceGet == "wood") tradeWith.resources.wood >= amountGet &&
//         (resourceGet == "brick") tradeWith.resources.brick >= amountGet &&
//         (resourceGet == "sheep") tradeWith.resources.sheep >= amountGet &&
//         (resourceGet == "wheat") tradeWith.resources.wheat >= amountGet &&
//         (resourceGet == "stone") tradeWith.resources.stone >= amountGet) {

//         // Deduct resources from current player and add to the other player
//         if (resourceGive == "wood") this->resources.wood -= amountGive;
//         if (resourceGive == "brick") this->resources.brick -= amountGive;
//         if (resourceGive == "sheep") this->resources.sheep -= amountGive;
//         if (resourceGive == "wheat") this->resources.wheat -= amountGive;
//         if (resourceGive == "stone") this->resources.stone -= amountGive;

//         if (resourceGet == "wood") this->resources.wood += amountGet;
//         if (resourceGet == "brick") this->resources.brick += amountGet;
//         if (resourceGet == "sheep") this->resources.sheep += amountGet;
//         if (resourceGet == "wheat") this->resources.wheat += amountGet;
//         if (resourceGet == "stone") this->resources.stone += amountGet;

//         // Deduct resources from the other player and add to the current player
//         if (resourceGive == "wood") tradeWith.resources.wood += amountGive;
//         if (resourceGive == "brick") tradeWith.resources.brick += amountGive;
//         if (resourceGive == "sheep") tradeWith.resources.sheep += amountGive;
//         if (resourceGive == "wheat") tradeWith.resources.wheat += amountGive;
//         if (resourceGive == "stone") tradeWith.resources.stone += amountGive;

//         if (resourceGet == "wood") tradeWith.resources.wood -= amountGet;
//         if (resourceGet == "brick") tradeWith.resources.brick -= amountGet;
//         if (resourceGet == "sheep") tradeWith.resources.sheep -= amountGet;
//         if (resourceGet == "wheat") tradeWith.resources.wheat -= amountGet;
//         if (resourceGet == "stone") tradeWith.resources.stone -= amountGet;

//         std::cout << "Trade was successful" << std::endl;
//     } else {
//         std::cout << "Trade cannot be executed due to insufficient resources" << std::endl;
//     }
// }


    // void Player::rollDice(std::vector<Player>& players, Board& board){
    //     int rolledNumber = (rand() % 6 + 1) + (rand() % 6 + 1); // Sum of two roll dice 
    //     std::cout << "Rolled number: " << rolledNumber << std::endl;

    //     // Go over all the vertex
    //     for (int i = 0; i < 54; ++i) { 
    //         std::cout << "check1" << std::endl;
    //         if (board.meshushe[i].id == rolledNumber) {
    //             std::cout << "check2" << std::endl;
    //             for (int player = 0; player < 3; player++) { // Go over all the player in the list player
    //                 std::cout << "check3" << std::endl;
    //                 for (int settlement : players[player].settelmentBuy) { // Go over all the settelment that the specific player buy
    //                     std::cout << "check4" << std::endl;
    //                     if (settlement == i) { // If the settlement is with the same number of the number that on the square
    //                     std::cout << "check5" << std::endl;
    //                         //player.resources += 1; // The player get one card of the resource
    //                         std::string resourceType = board.boardVertex[i].getResourceType();
    //                         std::cout << "check6" << std::endl;
    //                         if (resourceType == "wood") {
    //                             std::cout << "check7" << std::endl;
    //                             players[player].resources.wood += 1;
    //                             std::cout << "check8" << std::endl;
    //                         } else if (resourceType == "brick") {
    //                             std::cout << "check9" << std::endl;
    //                             players[player].resources.brick += 1;
    //                             std::cout << "check10" << std::endl;    
    //                         } else if (resourceType == "sheep") {
    //                             std::cout << "check11" << std::endl;
    //                             players[player].resources.sheep += 1;
    //                             std::cout << "check12" << std::endl;
    //                         } else if (resourceType == "wheat") {
    //                             std::cout << "check13" << std::endl;
    //                             players[player].resources.wheat += 1;
    //                             std::cout << "check14" << std::endl;
    //                         } else if (resourceType == "stone") {
    //                             std::cout << "check15" << std::endl;
    //                             players[player].resources.stone += 1;
    //                             std::cout << "check16" << std::endl;
    //                         }
    //                         std::cout << "check17" << std::endl;
    //                         std::cout << "You have add 1 more resource of the type :" << resourceType << std::endl;
    //                     }
    //                 }
    //                 for (int city : players[player].cityBuy) { // Go over all the city that the specific player buy
    //                 std::cout << "check18" << std::endl;
    //                     if (city == i) { // If the city is with the same number of the number that on the square
    //                     // player.resources.push_back(2); // Increment player's points for city
    //                         std::string resourceType = board.boardVertex[i].getResourceType();
    //                         if (resourceType == "wood") {
    //                             players[player].resources.wood += 2;
    //                         } else if (resourceType == "brick") {
    //                             players[player].resources.brick += 2;
    //                         } else if (resourceType == "sheep") {
    //                             players[player].resources.sheep += 2;
    //                         } else if (resourceType == "wheat") {
    //                             players[player].resources.wheat += 2;
    //                         } else if (resourceType == "stone") {
    //                             players[player].resources.stone += 2;
    //                         }
    //                         std::cout << "You have add 2 more resource of the type :" << resourceType << std::endl;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }





// void Player::rollDice(std::vector<Player>& players, Board& board) {
//     int rolledNumber = (rand() % 6 + 1) + (rand() % 6 + 1); // Sum of two rolled dice 
//     std::cout << "Rolled number: " << rolledNumber << std::endl;

//     // Go over all the vertices
//     for (int i = 0; i < 54; ++i) { // אולי 19 
//         std::cout << "check1" << std::endl;
//         if (board.meshushe[i].id == rolledNumber) {
//             std::cout << "check2" << std::endl;
//             for (Player& player : players) { // Go over all the players in the list 
//                 std::cout << "check3" << std::endl;
//                 for (int settlement : player.settelmentBuy) { // Go over all the settlements that the specific player bought
//                     if (settlement == i) { // If the settlement is with the same number as the number on the square
//                         std::string resourceType = board.boardVertex[i].getResourceType();
//                         player.addResources(resourceType, 1);
//                         std::cout << player.getPlayerName() << " has added 1 more resource of the type: " << resourceType << std::endl;
//                     }
//                 }
//                 for (int city : player.cityBuy) { // Go over all the cities that the specific player bought
//                     if (city == i) { // If the city is with the same number as the number on the square
//                         std::string resourceType = board.boardVertex[i].getResourceType();
//                         player.addResources(resourceType, 2);
//                         std::cout << player.getPlayerName() << " has added 2 more resources of the type: " << resourceType << std::endl;
//                     }
//                 }
//             }
//         }
//     }
// }

