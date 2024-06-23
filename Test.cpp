// Roniki04@gmail.com
#include <iostream>
#include <sstream>

#include "board.hpp" 
#include "card.hpp"  
#include "catan.hpp"  
#include "doctest.h"
#include "edge.hpp"
#include "knightCard.hpp"  
#include "meshushe.hpp"
#include "player.hpp"        
#include "promotionCard.hpp" 
#include "resource.hpp"
#include "vertex.hpp"
#include "victoryPointCard.hpp" 


// 111111111
TEST_CASE("board1") {
    Player player1("Player1");
    Player player2("Player2");
    Player player3("Player3");

    Catan catan(player1, player2, player3);
    std::vector<Player*> players = {&player1, &player2, &player3};
    Board board;

    player1.resources.wood = 1;
    player1.resources.brick = 1;
    player1.resources.wheat = 1;
    player1.resources.sheep = 1;

    player2.resources.wood = 1;
    player2.resources.brick = 1;
    player2.resources.wheat = 1;
    player2.resources.sheep = 1;

    player3.resources.wood = 1;
    player3.resources.brick = 1;
    player3.resources.wheat = 1;
    player3.resources.sheep = 1;

    player1.placeSettlement(board, 42);
    player2.placeSettlement(board, 40);
    player3.placeSettlement(board, 11);

    player1.rollDice(players, board);  // 7
    player1.rollDice(players, board);  // 6, player1 should get wheat, player3 should get brick

    SUBCASE("test - rollDice") {
        CHECK(player1.resources.wheat == 1);
        CHECK(player3.resources.brick == 1);

        player2.rollDice(players, board);  // 8, player2 should get wood

        CHECK(player2.resources.wood > 0);

        player3.rollDice(players, board);  // 6, player1 should get wheat, player3 should get brick

        CHECK(player1.resources.wood == 0);
        CHECK(player1.resources.brick == 0);
        CHECK(player1.resources.sheep == 0);
        CHECK(player1.resources.wheat == 2);
        CHECK(player1.resources.stone == 0);

        CHECK(player2.resources.wood == 1);
        CHECK(player2.resources.brick == 0);
        CHECK(player2.resources.sheep == 0);
        CHECK(player2.resources.wheat == 0);
        CHECK(player2.resources.stone == 0);

        CHECK(player3.resources.wood == 0);
        CHECK(player3.resources.brick == 2);
        CHECK(player3.resources.sheep == 0);
        CHECK(player3.resources.wheat == 0);
        CHECK(player3.resources.stone == 0);
    }

    SUBCASE("test - trade") {
        player1.trade(player2, "wheat", 1, "brick", 1);

        CHECK(player1.resources.wheat == 0);
        CHECK(player1.resources.brick == 1);
        CHECK(player2.resources.wheat == 1);
        CHECK(player2.resources.brick == 0);

        player1.trade(player3, "wood", 1, "brick", 1);

        CHECK(player1.resources.wood == 0);
        CHECK(player1.resources.brick == 1);
        CHECK(player3.resources.wood == 0);
        CHECK(player3.resources.brick == 1);
    }
}

// 333333333
TEST_CASE("test - printWinner") {
    Player player1("Player1");
    Player player2("Player2");
    Player player3("Player3");
    Player* player11 = &player1;
    Player* player22 = &player2;
    Player* player33 = &player3;

    Catan catan(player1, player2, player3);
    std::vector<Player*> players;

    players.push_back(player11);
    players.push_back(player22);
    players.push_back(player33);
    Board board;
    player1.placeSettlement(board, 23);
    player1.placeSettlement(board, 35);
    player1.placeSettlement(board, 33);
    player1.placeSettlement(board, 44);
    player1.placeSettlement(board, 51);

    player1.resources.wheat = 10;
    player1.resources.stone = 15;
    player1.placeCity(board, 23);
    player1.placeCity(board, 35);
    player1.placeCity(board, 33);
    player1.placeCity(board, 44);

    std::stringstream newBuffer; // To capture the output
    std::streambuf* originalBuffer = std::cout.rdbuf(newBuffer.rdbuf()); // Redirect std::cout to newBuffer

    catan.printWinner();
    std::string buf_data = newBuffer.str(); // Get the output
    std::cout.rdbuf(originalBuffer); // Reset std::cout
    CHECK(buf_data == "There is no winner.\n");

    newBuffer.str(""); // Clear the buffer
    player1.placeCity(board, 51);

    CHECK(player1.getPointsOfPlayer() == 10);

    originalBuffer = std::cout.rdbuf(newBuffer.rdbuf()); // Redirect std::cout to newBuffer
    newBuffer.str(""); 
    catan.printWinner();
    buf_data = newBuffer.str(); // Get the output
    std::cout.rdbuf(originalBuffer); // Reset std::cout
    CHECK(newBuffer.str() == "The winner is : Player1\n");
    std::cout.rdbuf(originalBuffer); 
}


// 222222222
TEST_CASE("board 2") {
    Player player1("Player1");
    Player player2("Player2");
    Player player3("Player3");

    Catan catan(player1, player2, player3);
    std::vector<Player*> players = {&player1, &player2, &player3};
    Board board;
    Card* card1 = new VictoryPointCard("Victory Point");
    VictoryPointCard* card2 = new VictoryPointCard("Victory Point");
    VictoryPointCard* card3 = new VictoryPointCard("Victory Point");
    VictoryPointCard* card4 = new VictoryPointCard("Victory Point");

    KnightCard* card5 = new KnightCard("Knight");
    KnightCard* card6 = new KnightCard("Knight");
    Card* card7 = new KnightCard("Knight");

    PromotionCard* card8 = new monopolyCard("Promotion");
    PromotionCard* card9 = new monopolyCard("Promotion");

    PromotionCard* card10 = new buildRoadCard("Promotion");
    PromotionCard* card11 = new buildRoadCard("Promotion");

    PromotionCard* card12 = new plentyYearCard("Promotion");
    PromotionCard* card13 = new plentyYearCard("Promotion");
    std::vector<Card*> listOfCard = {card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13};

    player1.resources.wood = 1;
    player1.resources.brick = 1;
    player1.resources.wheat = 1;
    player1.resources.sheep = 1;

    player2.resources.wood = 2;
    player2.resources.brick = 2;
    player2.resources.sheep = 1;
    player2.resources.wheat = 5;
    player2.resources.stone = 4;

    player3.resources.wood = 1;
    player3.resources.brick = 1;
    player3.resources.sheep = 1;
    player3.resources.wheat = 3;
    player3.resources.stone = 3;

    player1.placeSettlement(board, 11);
    player2.placeSettlement(board, 25);
    player2.placeSettlement(board, 35);
    player2.placeCity(board, 35);
    player3.placeSettlement(board, 42);
    player3.placeCity(board, 42);

    player2.rollDice(players, board);  // 5
    SUBCASE("test - buyDevelopmentCard") {
        Card* tempCard = player3.randomCard(listOfCard);

        std::stringstream newBuffer; // To capture the output
        std::streambuf* originalBuffer = std::cout.rdbuf(newBuffer.rdbuf()); // Redirect std::cout to newBuffer

        player2.buyDevelopmentCard(players, tempCard);  // player2 buy promotion card

        std::string buf_data = newBuffer.str(); // Get the output
        std::cout.rdbuf(originalBuffer); // Reset std::cout

        CHECK(buf_data == "Player2 buy a development card\n");
        newBuffer.str(""); // Clear the buffer

        CHECK(player2.resources.sheep == 0);
        CHECK(player2.resources.wheat == 0);
        CHECK(player2.resources.stone == 0);

        std::cout.rdbuf(originalBuffer); // Reset std::cout
    }

    SUBCASE("test - use promotion card"){
        std::stringstream newBuffer; // To capture the output
        std::streambuf* originalBuffer = std::cout.rdbuf(newBuffer.rdbuf()); // Redirect std::cout to newBuffer

        player2.developCardsBuy.push_back(card8);

        player2.developCardsBuy[0]->use(); // player2 use promotion card
        std::string buf_data = newBuffer.str();
        std::cout.rdbuf(originalBuffer);

        CHECK(buf_data == "Monopoly Card used\n");   
        newBuffer.str("");

        std::cout.rdbuf(originalBuffer);
    }

    SUBCASE("test - throwHalf") {

        player2.resources.sheep +=3;
        player2.resources.wheat +=1;
        player2.resources.stone +=3;

        player2.throwHalf();

        CHECK(player2.resources.sheep == 0);
        CHECK(player2.resources.wheat == 0);
        CHECK(player2.resources.stone == 4);
     
    }
}


TEST_CASE("board 3"){
    Player player1("Player1");
    Player player2("Player2");
    Player player3("Player3");

    Catan catan(player1, player2, player3);
    std::vector<Player*> players = {&player1, &player2, &player3};
    Board board;

    player1.resources.wood = 1;
    player1.resources.brick = 1;
    player1.resources.wheat = 1;
    player1.resources.sheep = 1;

    player2.resources.wood = 2;
    player2.resources.brick = 2;
    player2.resources.wheat = 1;
    player2.resources.sheep = 1;

    player3.resources.wood = 1;
    player3.resources.brick = 1;
    player3.resources.wheat = 1;
    player3.resources.sheep = 1;

    player1.placeSettlement(board, 23);
    player2.placeSettlement(board, 20);
    player3.placeSettlement(board, 42);
    player2.placeRoad(board, 26);

    std::cout << "board 3" << std::endl;

    player1.rollDice(players, board);  // 6
    player1.rollDice(players, board);  // 11
    player1.rollDice(players, board);  // 7

    SUBCASE("test - placeRoad") {
        std::cout << "placeRoad" << std::endl;
        player2.placeRoad(board, 19);

    }

    SUBCASE("test - placeSettlement") {
        std::cout << "placeSettlement" << std::endl;// 7,6,4
        player2.resources.wood += 1;
        player2.resources.wheat += 1;
        player2.resources.sheep += 1;
        player2.placeSettlement(board, 19);

    }

    SUBCASE("test - placeCity") {
        std::cout << "placeCity" << std::endl; // 8,2,7
        player3.resources.wheat += 2;
        player3.resources.stone += 3;
        player3.placeCity(board, 42);

    }

}
