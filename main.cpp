// Roniki04@gmail.com
#include <iostream>
#include <string>

#include "board.hpp"
#include "catan.hpp"
#include "player.hpp"
#include "card.hpp"
#include "knightCard.hpp"
#include "victoryPointCard.hpp"
#include "promotionCard.hpp"

using namespace std;

int main() {

    // Create a player
    Player player1("Player1");
    Player player2("Player2");
    Player player3("Player3");
    Player* player11 = &player1;
    Player* player22 = &player2;
    Player* player33 = &player3;

    Catan catan(player1, player2, player3);

    // Create a board
    Board board;
    board.printBoard();
    // Create a vector of players
    std::vector<Player*> players;
    // Add the player to the vector
    players.push_back(player11);
    players.push_back(player22);
    players.push_back(player33);

    std::cout << "The players are: ";
    for (Player* player : players) {
        std::cout << player->getPlayerName() << " ";
    }
    std::cout << std::endl;

    // There is 13 cards in the game
    Card* card1 = new VictoryPointCard("Victory Point");
    Card* card2 = new VictoryPointCard("Victory Point");
    Card* card3 = new VictoryPointCard("Victory Point");
    Card* card4 = new VictoryPointCard("Victory Point");

    Card* card5 = new KnightCard("Knight");
    Card* card6 = new KnightCard("Knight");
    Card* card7 = new KnightCard("Knight");

    Card* card8 = new monopolyCard("Promotion");
    Card* card9 = new monopolyCard("Promotion");

    Card* card10 = new buildRoadCard("Promotion");
    Card* card11 = new buildRoadCard("Promotion");

    Card* card12 = new plentyYearCard("Promotion");
    Card* card13 = new plentyYearCard("Promotion");  

    std::vector<Card*> listOfCard = {card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13};

    player1.resources.wood = 4;
    player1.resources.brick = 4;
    player1.resources.sheep = 2;
    player1.resources.wheat = 2;

    player2.resources.wood = 4;
    player2.resources.brick = 4;
    player2.resources.sheep = 2;
    player2.resources.wheat = 2;

    player3.resources.wood = 4;
    player3.resources.brick = 4;
    player3.resources.sheep = 2;
    player3.resources.wheat = 2;

    // Place the first 2 settlements for each player
    int ver1 = 29;
    player1.placeSettlement(board, ver1);
    int edge1 = 41;
    player1.placeRoad(board, edge1);
    std::cout << "Player1 resources - wood: " << players[0]->resources.wood << ", brick: " << players[0]->resources.brick << ", sheep: " << players[0]->resources.sheep << ", wheat: " << players[0]->resources.wheat << ", stone: " << players[0]->resources.stone << std::endl;

    int ver2 = 40;
    player2.placeSettlement(board, ver2);
    int edge2 = 56;
    player2.placeRoad(board, edge2);

    int ver3 = 13;
    player3.placeSettlement(board, ver3);
    int edge3 = 21;
    player3.placeRoad(board, edge3);

    int ver33 = 34;
    player3.placeSettlement(board, ver33);
    int edge33 = 46;
    player3.placeRoad(board, edge33);
    players[2]->resources.wood += 1;
    players[2]->resources.sheep += 1;
    players[2]->resources.wheat += 1;
  
    int ver22 = 43;
    player2.placeSettlement(board, ver22);
    int edge22 = 58;
    player2.placeRoad(board, edge22);
    players[1]->resources.wheat += 2;
    players[1]->resources.sheep += 1;

    int ver11 = 10;
    player1.placeSettlement(board, ver11);
    int edge11 = 12;
    player1.placeRoad(board, edge11);
    players[0]->resources.stone += 1;
    players[0]->resources.sheep += 1;
    players[0]->resources.brick += 1;

    std::cout << "Player1 resources - wood: " << players[0]->resources.wood << ", brick: " << players[0]->resources.brick << ", sheep: " << players[0]->resources.sheep << ", wheat: " << players[0]->resources.wheat << ", stone: " << players[0]->resources.stone << std::endl;
    std::cout << "Player2 resources - wood: " << players[1]->resources.wood << ", brick: " << players[1]->resources.brick << ", sheep: " << players[1]->resources.sheep << ", wheat: " << players[1]->resources.wheat << ", stone: " << players[1]->resources.stone << std::endl;
    std::cout << "Player3 resources - wood: " << players[2]->resources.wood << ", brick: " << players[2]->resources.brick << ", sheep: " << players[2]->resources.sheep << ", wheat: " << players[2]->resources.wheat << ", stone: " << players[2]->resources.stone << std::endl;

    std::cout << " ~~~~~~~~~" << std::endl;
    std::cout << "The game start" << std::endl;
    std::cout << " ~~~~~~~~~" << std::endl;

    // The first player
    player1.rollDice(players, board);  // 7
    player1.rollDice(players, board);  // 6
    player1.trade(player3, "stone", 1, "wood", 1);
    player1.placeRoad(board, 19);
    player1.endTurn();

    // The second player
    player2.rollDice(players, board);  // 8
    player2.endTurn();

    // The third player
    player3.rollDice(players, board);  // 6
    Card* tempCard = player3.randomCard(listOfCard);
    player3.buyDevelopmentCard(players, tempCard);
    player3.endTurn();

    // The first player
    player1.rollDice(players, board);  // 6      
    player1.trade(player2, "brick", 1, "wheat", 1);
    player1.placeSettlement(board, 19);
    player1.endTurn();

    // The second player
    player2.rollDice(players, board);  // 5
    player2.placeRoad(board, 63);
    player2.endTurn();

    // The third player
    player3.rollDice(players, board);  // 5
    player3.endTurn();

    std::cout << "Player1 resources - wood: " << players[0]->resources.wood << ", brick: " << players[0]->resources.brick << ", sheep: " << players[0]->resources.sheep << ", wheat: " << players[0]->resources.wheat << ", stone: " << players[0]->resources.stone << std::endl;
    std::cout << "Player2 resources - wood: " << players[1]->resources.wood << ", brick: " << players[1]->resources.brick << ", sheep: " << players[1]->resources.sheep << ", wheat: " << players[1]->resources.wheat << ", stone: " << players[1]->resources.stone << std::endl;
    std::cout << "Player3 resources - wood: " << players[2]->resources.wood << ", brick: " << players[2]->resources.brick << ", sheep: " << players[2]->resources.sheep << ", wheat: " << players[2]->resources.wheat << ", stone: " << players[2]->resources.stone << std::endl;

    // the game is finish
    player1.printPoints();
    player2.printPoints();
    player3.printPoints();

    catan.printWinner();

    return 0;
}
