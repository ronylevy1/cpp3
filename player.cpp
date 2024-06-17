#include "player.hpp"

#include <algorithm>  // for std::find
#include <cstdlib>    // for rand()
#include <iostream>
#include <string>
#include <vector>

#include "board.hpp"
#include "edge.hpp"
#include "meshushe.hpp"
#include "resource.hpp"
#include "vertex.hpp"


void Player::rollDice(std::vector<Player*>& players, Board& board) {
    int rolledNumber = (rand() % 6 + 1) + (rand() % 6 + 1);  // Sum of two dice rolls
    std::cout << "Rolled number: " << rolledNumber << std::endl;

    // Go over all the meshushe
    for (int i = 0; i < 19; i++) {
        if (board.meshushe[i].idMesh == rolledNumber) {
            for (Player* tempPlayer : players) {
                // Check if the player has a settlement on any vertex of the current meshushe
                bool hasSettlement = false;
                bool hasCity = false;
                for (int index = 0; index < 6; index++) {
                    for (int settlement : tempPlayer->settelmentBuy) {
                        if (settlement == board.meshushe[i].vertex[index].getId()) {
                            hasSettlement = true;
                            break;
                        }
                    }
                    for (int city : tempPlayer->cityBuy) {
                        if (city == board.meshushe[i].vertex[index].getId()) {
                            hasCity = true;
                            break;
                        }
                    }

                    if (hasSettlement) {
                        std::string resourceType = board.meshushe[i].resourceType;
                        if (resourceType == "wood") {
                            tempPlayer->resources.wood += 1;
                            hasSettlement = false;
                        } else if (resourceType == "brick") {
                            tempPlayer->resources.brick += 1;
                            hasSettlement = false;
                        } else if (resourceType == "sheep") {
                            tempPlayer->resources.sheep += 1;
                            hasSettlement = false;
                        } else if (resourceType == "wheat") {
                            tempPlayer->resources.wheat += 1;
                            hasSettlement = false;
                        } else if (resourceType == "stone") {
                            tempPlayer->resources.stone += 1;
                            hasSettlement = false;
                        }
                    }

                    if (hasCity) {
                        std::string resourceType = board.meshushe[i].resourceType;
                        if (resourceType == "wood") {
                            tempPlayer->resources.wood += 2;
                            hasCity = false;
                        } else if (resourceType == "brick") {
                            tempPlayer->resources.brick += 2;
                            hasCity = false;
                        } else if (resourceType == "sheep") {
                            tempPlayer->resources.sheep += 2;
                            hasCity = false;
                        } else if (resourceType == "wheat") {
                            tempPlayer->resources.wheat += 2;
                            hasCity = false;
                        } else if (resourceType == "stone") {
                            tempPlayer->resources.stone += 2;
                            hasCity = false;
                        }
                    }
                }
            }
        }
    }
}

// TODO
void Player::endTurn() {

}

void Player::buyDevelopmentCard() {
    resources.wheat -= 1;
    resources.sheep -= 1;
    resources.stone -= 1;
    std::cout << playerName << " buy a development card" << std::endl;
}

void Player::printPoints() {
    std::cout << "The num of points " << playerName << " have is : " << pointsOfPlayer << std::endl;
}

void Player::throwHalf() {  
    //count the number of resources
    int wood_count = this->resources.wood;
    int brick_count = this->resources.brick;
    int sheep_count = this->resources.sheep;
    int wheat_count = this->resources.wheat;
    int stone_count = this->resources.stone;

    int num = (wood_count + brick_count + sheep_count + wheat_count + stone_count) / 2;
    if(this->resources.wood >0){
        if(wood_count > num){
            this->resources.wood -= num;
            return;
        }else{
            num -= wood_count;
            this->resources.wood = 0;
        }
    }
    if(this->resources.brick >0){
        if(brick_count > num){
            this->resources.brick -= num;
            return;
        }else{
            num -= brick_count;
            this->resources.brick = 0;
        }
    }
    if(this->resources.sheep >0){
        if(sheep_count > num){
            this->resources.sheep -= num;
            return;
        }else{
            num -= sheep_count;
            this->resources.sheep = 0;
        }
    }
    if(this->resources.wheat >0){
        if(wheat_count > num){
            this->resources.wheat -= num;
            return;
        }else{
            num -= wheat_count;
            this->resources.wheat = 0;
        }
    }
    if(this->resources.stone >0){
        if(stone_count > num){
            this->resources.stone -= num;
            return;
        }else{
            num -= stone_count;
            this->resources.stone = 0;
        }
    }
}

std::string Player::getPlayerName() const {
    return playerName;
}

int Player::getPointsOfPlayer() const {
    return pointsOfPlayer;
}

std::vector<Vertex> Player::placeSettlement(Board& board, int index) {  
    board.setVertex(index);                                             
    settelmentBuy.push_back(index);                                     
    pointsOfPlayer += 1;                                                
    resources.brick -= 1;                                               
    resources.wood -= 1;
    resources.sheep -= 1;
    resources.wheat -= 1;
    std::cout << playerName << " have placed a settlement on vertex " << index << std::endl;
    return std::vector<Vertex>();
}

std::vector<Vertex> Player::placeCity(Board& board, int index) {
    auto it = std::find(settelmentBuy.begin(), settelmentBuy.end(), index);  // Check if the vertex is a settlement
    if (it == settelmentBuy.end()) {                                         // If the vertex is not a settlement
        std::cout << "You can place a city only on a settlement" << std::endl;
        return std::vector<Vertex>();
    }

    settelmentBuy.erase(it);  // Remove the settlement from the list of settlements
    board.setVertex(index);
    cityBuy.push_back(index);  // Add the city to the list of cities
    pointsOfPlayer += 1;       // Add a point to the player
    resources.wheat -= 2;
    resources.stone -= 3;
    std::cout << playerName << " have placed a city on vertex " << index << std::endl;
    return std::vector<Vertex>();
}

std::vector<Edge> Player::placeRoad(Board& board, int index) {
    board.setEdge(index);  // Set the edge as a road
    resources.brick -= 1;  // Deduct the required resources for placing a settlement
    resources.wood -= 1;
    std::cout << playerName << " have placed a road on edge " << index << std::endl;
    return std::vector<Edge>();
}

void Player::trade(Player& tradeWith, std::string resourceGive, int amountGive, std::string resourceGet, int amountGet) {
    // Check if the player has enough resources to give
    if ((resourceGive == "wood" && this->resources.wood < amountGive) ||
        (resourceGive == "brick" && this->resources.brick < amountGive) ||
        (resourceGive == "sheep" && this->resources.sheep < amountGive) ||
        (resourceGive == "wheat" && this->resources.wheat < amountGive) ||
        (resourceGive == "stone" && this->resources.stone < amountGive)) {
        std::cout << "You don't have enough resources to trade" << std::endl;
        return;
    }

    // Check if the other player has enough resources to give
    if ((resourceGet == "wood" && tradeWith.resources.wood < amountGet) ||
        (resourceGet == "brick" && tradeWith.resources.brick < amountGet) ||
        (resourceGet == "sheep" && tradeWith.resources.sheep < amountGet) ||
        (resourceGet == "wheat" && tradeWith.resources.wheat < amountGet) ||
        (resourceGet == "stone" && tradeWith.resources.stone < amountGet)) {
        std::cout << "The other player doesn't have enough resources to trade" << std::endl;
        return;
    }

    // Execute the trade: deduct the resources from the current player and add to the other player
    if (resourceGive == "wood") this->resources.wood -= amountGive;
    if (resourceGive == "brick") this->resources.brick -= amountGive;
    if (resourceGive == "sheep") this->resources.sheep -= amountGive;
    if (resourceGive == "wheat") this->resources.wheat -= amountGive;
    if (resourceGive == "stone") this->resources.stone -= amountGive;

    if (resourceGet == "wood") this->resources.wood += amountGet;
    if (resourceGet == "brick") this->resources.brick += amountGet;
    if (resourceGet == "sheep") this->resources.sheep += amountGet;
    if (resourceGet == "wheat") this->resources.wheat += amountGet;
    if (resourceGet == "stone") this->resources.stone += amountGet;

    // Execute the trade for the other player: add the resources from the current player and deduct from the other player
    if (resourceGive == "wood") tradeWith.resources.wood += amountGive;
    if (resourceGive == "brick") tradeWith.resources.brick += amountGive;
    if (resourceGive == "sheep") tradeWith.resources.sheep += amountGive;
    if (resourceGive == "wheat") tradeWith.resources.wheat += amountGive;
    if (resourceGive == "stone") tradeWith.resources.stone += amountGive;

    if (resourceGet == "wood") tradeWith.resources.wood -= amountGet;
    if (resourceGet == "brick") tradeWith.resources.brick -= amountGet;
    if (resourceGet == "sheep") tradeWith.resources.sheep -= amountGet;
    if (resourceGet == "wheat") tradeWith.resources.wheat -= amountGet;
    if (resourceGet == "stone") tradeWith.resources.stone -= amountGet;

    std::cout << "Trade was successful" << std::endl;
}

