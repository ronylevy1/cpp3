// Roniki04@gmail.com

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
#include "card.hpp"


void Player::rollDice(std::vector<Player*>& players, Board& board) {
    int rolledNumber = (rand() % 6 + 1) + (rand() % 6 + 1);  // Sum of two dice rolls
    std::cout << "Rolled number: " << rolledNumber << std::endl;

    // Go over all the meshushe
    for (int i = 0; i < 19; i++) {
        if (board.meshushe[i].idMesh == rolledNumber) { // Check if the meshushe has the same id as the rolled number
            for (Player* tempPlayer : players) {       // Go over all the players
                bool hasSettlement = false; 
                bool hasCity = false;
                for (int index = 0; index < 6; index++) { // Go over all the vertexes of the meshushe
                    for (int settlement : tempPlayer->settelmentBuy) { 
                        if (settlement == board.meshushe[i].vertex[index].getId()) { // Check if the player has a settlement on the vertex
                            hasSettlement = true;
                            break;
                        }
                    }
                    for (int city : tempPlayer->cityBuy) { // Check if the player has a city on the vertex
                        if (city == board.meshushe[i].vertex[index].getId()) {
                            hasCity = true;
                            break;
                        }
                    }

                    if (hasSettlement) { // If the player has a settlement on the vertex
                        std::string resourceType = board.meshushe[i].resourceType;
                        // Add the resource to the player
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

                    if (hasCity) { // If the player has a city on the vertex
                        std::string resourceType = board.meshushe[i].resourceType;
                        // Add the resource to the player
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


void Player::endTurn() {
    std::cout << playerName << " end his turn" << std::endl;
}

void Player::buyDevelopmentCard(std::vector<Player*>& players, Card* card) {
    resources.wheat -= 1;
    resources.sheep -= 1;
    resources.stone -= 1;
    std::cout << playerName << " buy a development card" << std::endl;
    developCardsBuy.push_back(card);
    // If the card is a victory card
    if((*card).getType() == "victory") {
        pointsOfPlayer += 1;
    }

    // If there is 2 type of knight cards
    if(developCardsBuy.size() >= 2){
        int count = 0;
        for(Card* card1 : developCardsBuy) {
            if((*card1).getType() == "knight") {
                count++;
            }
        }
        if(count == 2) {
            pointsOfPlayer += 2;
        }
    }

    // If the card is a monopoly card - raffle random resource and that resource from all the players
    if((*card).getType() == "monopoly") {
        std::vector<std::string> resources = {"wood", "brick", "sheep", "wheat", "stone"};
        int randomIndex = rand() % 5;
        std::string resource = resources[randomIndex];
        for(Player* player : players) {
            if(player->getPlayerName() != playerName) {
                int amount = player->resources.getResourceAmount(resource);
                player->resources.incrementResource(resource, -amount);
                player->resources.incrementResource(resource, amount);
            }
        }
    }

    // If the card is a road building card - give the player the resources to build 2 roads
    if((*card).getType() == "road building") {
        resources.brick += 2;
        resources.wood += 2;
    }

    // If the card is a year of plenty card - raffle random 2 resources and give them to the player
    if((*card).getType() == "year of plenty") {
        std::vector<std::string> resources = {"wood", "brick", "sheep", "wheat", "stone"};
        int randomIndex1 = rand() % 5;
        int randomIndex2 = rand() % 5;
        std::string resource1 = resources[randomIndex1];
        std::string resource2 = resources[randomIndex2];
        std::cout << "The player got the resources: " << resource1 << " and " << resource2 << std::endl;
        this->resources.incrementResource(resource1, 1);
        this->resources.incrementResource(resource2, 1);
    }
}

void Player::printPoints() {
    std::cout << "The num of points " << playerName << " have is : " << pointsOfPlayer << std::endl;
}

void Player::throwHalf() {  
    // count the number of resources
    int wood_count = this->resources.wood;
    int brick_count = this->resources.brick;
    int sheep_count = this->resources.sheep;
    int wheat_count = this->resources.wheat;
    int stone_count = this->resources.stone;

    int num = (wood_count + brick_count + sheep_count + wheat_count + stone_count) / 2; // the number of resources to throw
    if(this->resources.wood > 0){ // check if the player has wood
        if(wood_count > num){ // check if the number of wood is bigger than the number of resources to throw
            this->resources.wood -= num; // throw the resources
            return;
        }else{
            num -= wood_count; // if the number of wood is smaller than the number of resources to throw
            this->resources.wood = 0; // throw all the wood
        }
    }
    if(this->resources.brick > 0){ // check if the player has brick
        if(brick_count > num){ // check if the number of brick is bigger than the number of resources to throw
            this->resources.brick -= num; // throw the resources
            return;
        }else{
            num -= brick_count; // if the number of brick is smaller than the number of resources to throw
            this->resources.brick = 0; // throw all the brick
        }
    }
    if(this->resources.sheep > 0){ // check if the player has sheep
        if(sheep_count > num){ // check if the number of sheep is bigger than the number of resources to throw
            this->resources.sheep -= num; // throw the resources
            return;
        }else{
            num -= sheep_count; // if the number of sheep is smaller than the number of resources to throw
            this->resources.sheep = 0; // throw all the sheep
        }
    }
    if(this->resources.wheat > 0){ // check if the player has wheat
        if(wheat_count > num){ // check if the number of wheat is bigger than the number of resources to throw
            this->resources.wheat -= num; // throw the resources
            return;
        }else{
            num -= wheat_count; // if the number of wheat is smaller than the number of resources to throw
            this->resources.wheat = 0; // throw all the wheat
        }
    }
    if(this->resources.stone > 0){ // check if the player has stone
        if(stone_count > num){ // check if the number of stone is bigger than the number of resources to throw
            this->resources.stone -= num; // throw the resources
            return;
        }else{
            num -= stone_count; // if the number of stone is smaller than the number of resources to throw
            this->resources.stone = 0; // throw all the stone
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
    board.setVertex(index); // Set the vertex as a settlement                                      
    settelmentBuy.push_back(index); // Add the settlement to the list of settlements                                  
    pointsOfPlayer += 1; // Add a point to the player                                           
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
    board.setVertex(index); // Set the vertex as a city
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

    // Take the resources from the current player and give to the other player
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

    // Take the resources from the other player and give to the current player
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


Card* Player::randomCard(std::vector<Card*>& listCard) {
    int randomIndex = rand() % listCard.size(); // Get a random index
    return listCard[randomIndex]; // Return the card
}