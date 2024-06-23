#include "catan.hpp"

#include <iostream>

Catan::Catan(Player& p1, Player& p2, Player& p3) : players{&p1, &p2, &p3} {
    gameBoard.initialize(); // Initialize the board
}

void Catan::ChooseStartingPlayer() {
    std::cout << "The starting player is : " << firstPlayer() << std::endl;
}

std::string Catan::firstPlayer() {
    return players[0]->getPlayerName(); // Return the name of the first player
}

void Catan::setCard(int index, Card* card) {
    cards[index] = card;
}

Card* Catan::getCard(int index) {
    return cards[index];
}

void Catan::printWinner() {
    int pointP1 = players[0]->getPointsOfPlayer(); // Get the points of the first player
    int pointP2 = players[1]->getPointsOfPlayer(); // Get the points of the second player
    int pointP3 = players[2]->getPointsOfPlayer(); // Get the points of the third player

    if (pointP1 == 10) {
        std::cout << "The winner is : " << players[0]->getPlayerName() << std::endl;
    } else if (pointP2 == 10) {
        std::cout << "The winner is : " << players[1]->getPlayerName() << std::endl;
    } else if (pointP3 == 10) {
        std::cout << "The winner is : " << players[3]->getPlayerName() << std::endl;
    } else {
        std::cout << "There is no winner." << std::endl;
    }
}