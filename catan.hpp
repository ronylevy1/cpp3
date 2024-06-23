// Roniki04@gmail.com
#include <string>

#include "board.hpp"
#include "card.hpp"
#include "meshushe.hpp"
#include "player.hpp"

class Catan {
   private:
    Player* players[3];  // The game for 3 players
    Board gameBoard;     // The board of the game
    Card* cards[3];      // The cards of the game, first - 6 promotion cards, second - 3 knight cards and third - 4 victory point cards

   public:
    Catan(Player& p1, Player& p2, Player& p3);  // Constructor that initializes the game with 3 players

    void setPlayer(int index, Player& player) {
        players[index] = &player;
    }

    Player* getPlayer(int index) {
        return players[index];
    }

    void setBoard(const Board& board) {
        gameBoard = board;
    }

    Board& getBoard() {
        return gameBoard;
    }

    void setCard(int index, Card* card); // Set the card 
    Card* getCard(int index);             // Get the card

    void ChooseStartingPlayer();  // Choose the starting player
    std::string firstPlayer();    // Return the name of the first player
    void printWinner();           // Print the winner of the game
};
