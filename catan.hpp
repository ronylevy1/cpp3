
#include <string>
#include "player.hpp"
#include "board.hpp"
#include "meshushe.hpp"

class Catan{
    private:
    Player players[3]; // The game for 3 players
    Board gameBoard;

    public:
    Catan(const Player& p1, const Player& p2, const Player& p3);

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
    void ChooseStartingPlayer();
    std::string firstPlayer();
    void printWinner();
};


