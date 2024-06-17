#include <iostream>
#include "catan.hpp"

Catan::Catan(const Player& p1, const Player& p2, const Player& p3) : players{p1, p2, p3} {
    gameBoard.initialize();
}

void Catan::ChooseStartingPlayer(){
    std::cout << "The starting player is : " <<  firstPlayer() << std::endl;
}

std::string Catan::firstPlayer(){
    return players[0].getPlayerName();
}

void Catan::printWinner(){
    int pointP1 = players[0].getPointsOfPlayer();
    int pointP2 = players[1].getPointsOfPlayer();
    int pointP3 = players[2].getPointsOfPlayer();

    if(pointP1 == 10){
        std::cout << "The winner is : " << players[0].getPlayerName() << std::endl;
    }
    else if(pointP2 == 10){
        std::cout << "The winner is : " << players[1].getPlayerName() << std::endl;
    } 
    else if(pointP3 == 10){
        std::cout << "The winner is : "  << players[3].getPlayerName() << std::endl;
    }
    else {
        std::cout << "There is no winner." << std::endl;
    }
}