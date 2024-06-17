
#include <string>
#include "player.hpp"
#include "board.hpp"
#include "meshushe.hpp"

class Catan{
    private:
    Player players[3]; // The game for 3 players
    Board gameBoard; // The board of the game

    public:
    Catan(const Player& p1, const Player& p2, const Player& p3); // Constructor that initializes the game with 3 players

    void setPlayer(int index, const Player& player) {
        players[index] = player;
    }

    Player& getPlayer(int index) {
        return players[index];
    }

    void setBoard(const Board& board) {
    gameBoard = board;
    }

    Board& getBoard() {
        return gameBoard;
    }
    void ChooseStartingPlayer(); // Choose the starting player
    std::string firstPlayer(); // Return the name of the first player
    void printWinner(); // Print the winner of the game
};


