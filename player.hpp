#include <vector>
#include <string>
#include <cstdlib> // for rand()
#include "edge.hpp"
#include "vertex.hpp"
#include "board.hpp"
#include "resource.hpp"


#ifndef Player_hpp
#define Player_hpp
class Player{
    private:
        std::string playerName; // The name of the player 
        //std::string playerColor; // The color of the player
        std::vector<int> developCardsBuy; // All the develop cards i buy
        int pointsOfPlayer; // The point i have

    public:
        std::vector<int> settelmentBuy; // All the settelment I bought
        std::vector<int> cityBuy; // All the city i buy
        std::vector<int> roadBut; // All the roud i buy
        std::vector<int> cardsBuy; // All the cards i buy
        std::vector<Player> otherPlayer;
        

        //Player(const std::string& playerName, const std::string& playerColor) : playerName(playerName), playerColor(playerColor), pointsOfPlayer(0){} // Constructor that initializes a player object with the given player name and sets player points to 0
        Player(const std::string& playerName) : playerName(playerName), pointsOfPlayer(0){} // Constructor that initializes a player object with the given player name and sets player points to 0

        Resource resources; // The resources of the player

        std::string getPlayerName() const;
        int getPointsOfPlayer() const;
        void rollDice(std::vector<Player>& players, Board& board);
        void endTurn();
        void trade(Player& tradeWith, std::string resourceGive, int amountGive, int amountGet); // You can trade one card per turn
        void trade(Player& tradeWith, std::string resourceGive, int amountGive, std::string resourceGet, int amountGet);
        void buyDevelopmentCard();
        void printPoints();
        void throwHalf(std::vector<int> cardsBuy); // Throw half of the cards
        std::string getColor() const;
        
        std::vector<Vertex> placeSettlement(Board* board, int index); // Place the settelment on the board
        std::vector<Vertex> placeCity(Board& board, int index); // Place the city on the board
        std::vector<Edge> placeRoad(Board& board, int index); // Place the road on the board

       // void addResources(std::string resourceType, int amount);

};

#endif // Player_hpp



// #ifndef Resources_hpp
// #define Resources_hpp
// class Resources {
// public:
//     int wood = 0;
//     int brick = 0;
//     int sheep = 0;
//     int wheat = 0;
//     int stone = 0;
    
//     // void incrementResource(const std::string& resourceType, int amount) {
//     //     if (resourceType == "wood") {
//     //         wood += amount;
//     //     } else if (resourceType == "brick") {
//     //         brick += amount;
//     //     } else if (resourceType == "sheep") {
//     //         sheep += amount;
//     //     } else if (resourceType == "wheat") {
//     //         wheat += amount;
//     //     } else if (resourceType == "stone") {
//     //         stone += amount;
//     //     }
//     // }
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

// };

// #endif // Resources_hpp