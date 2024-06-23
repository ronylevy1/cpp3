// Roniki04@gmail.com
#include <vector>
#include <string>
#include <cstdlib> // for rand()
#include "edge.hpp"
#include "vertex.hpp"
#include "board.hpp"
#include "resource.hpp"
#include "card.hpp"

#pragma once
class Player{
    private:
        std::string playerName; // The name of the player 
        int pointsOfPlayer; // The point I have

    public:
        std::vector<Card*> developCardsBuy; // Development cards I buy
        std::vector<int> settelmentBuy; // Settelment I buy
        std::vector<int> cityBuy; // City I buy
        std::vector<int> roadBut; // Road I buy

        Player(const std::string& playerName) : playerName(playerName), pointsOfPlayer(0){} // Constructor

        Resource resources; // The resources of the player

        std::string getPlayerName() const; // Get the name of the player
        int getPointsOfPlayer() const; // Get the points of the player

        void rollDice(std::vector<Player*>& players, Board& board); // Roll the dice
        void endTurn(); // End the turn
        void trade(Player& tradeWith, std::string resourceGive, int amountGive, std::string resourceGet, int amountGet); // Trade with another player
        void buyDevelopmentCard(std::vector<Player*>& players, Card* card); // Buy a development card
        void printPoints(); // Print the points of the player
        void throwHalf(); // Throw half of the cards
        Card* randomCard(std::vector<Card*>& listCard); // Get a random card
        
        std::vector<Vertex> placeSettlement(Board& board, int index); // Place the settelment on the board
        std::vector<Vertex> placeCity(Board& board, int index); // Place the city on the board
        std::vector<Edge> placeRoad(Board& board, int index); // Place the road on the board
};
