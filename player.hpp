#include <vector>
#include <string>
#include <cstdlib> // for rand()
#include "edge.hpp"
#include "vertex.hpp"
#include "board.hpp"
#include "resource.hpp"

#pragma once
class Player{
    private:
        std::string playerName; // The name of the player 
        std::vector<int> developCardsBuy; // All the develop cards i buy
        int pointsOfPlayer; // The point i have

    public:
        std::vector<int> settelmentBuy; // All the settelment I bought
        std::vector<int> cityBuy; // All the city i buy
        std::vector<int> roadBut; // All the roud i buy
        std::vector<int> cardsBuy; // All the cards i buy
        std::vector<Player> otherPlayer;
        

        Player(const std::string& playerName) : playerName(playerName), pointsOfPlayer(0){} // Constructor that initializes a player object with the given player name and sets player points to 0

        Resource resources; // The resources of the player

        std::string getPlayerName() const;
        int getPointsOfPlayer() const;
        void rollDice(std::vector<Player*>& players, Board& board);
        void endTurn();
        void trade(Player& tradeWith, std::string resourceGive, int amountGive, std::string resourceGet, int amountGet);
        void buyDevelopmentCard();
        void printPoints();
        void throwHalf(); // Throw half of the cards
        
        std::vector<Vertex> placeSettlement(Board& board, int index); // Place the settelment on the board
        std::vector<Vertex> placeCity(Board& board, int index); // Place the city on the board
        std::vector<Edge> placeRoad(Board& board, int index); // Place the road on the board


};
