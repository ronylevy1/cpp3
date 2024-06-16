
#include <string>
#include "player.hpp"
#include "board.hpp"
#include "meshushe.hpp"

class Catan{
    private:
    Player players[3]; // The game for 3 players
    //Meshushe meshushe[19];
    Board* gameBoard;

    public:
    Catan(const Player& p1, const Player& p2, const Player& p3) : players{p1, p2, p3} {
        gameBoard->initialize();
    }


    // Catan(const Player& p1, const Player& p2, const Player& p3) : gameBoard() {
    //     players[0] = p1;
    //     players[1] = p2;
    //     players[2] = p3;
    //     gameBoard.initialize();
    // }

    // Catan(const Player& p1, const Player& p2, const Player& p3) : players{p1,p2,p3}, gameBoard{}{
    //     gameBoard.initialize();
    // }

    void setPlayer(int index, const Player& player) {
        players[index] = player;
    }

    Player& getPlayer(int index) {
        return players[index];
    }

    // void setBoard(const Board& board) {
    // gameBoard = board;
    // }

    Board* getBoard() {
        return gameBoard;
    }
    void ChooseStartingPlayer();
    std::string firstPlayer();
    std::string whoPlay();
    void printWinner();


};


