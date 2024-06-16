// #include <iostream>
// #include "player.hpp"
// #include "board.hpp"

// // void setColorAndState(Player& player, Board& board) {
// //     std::string colorCode;
// //     if(player.getColor() == "blue"){
// //         colorCode = "\033[1;34m";
// //     } else if(player.getColor() == "green"){
// //         colorCode = "\033[1;32m";
// //     } else if(player.getColor() == "red"){
// //         colorCode = "\033[1;31m";
// //     }
// //     for(const Vertex& vertex : player.placeSettlement()){
// //         board.setSettlementState(vertex.getId(), colorCode);
// //     }
// //     for(const Vertex& vertex : player.placeCity()){
// //         board.setCityState(vertex.getId(), colorCode);
// //     }
// //     for(const Edge& edge : player.placeRoad()){
// //         board.setRoadState(edge.getId(), colorCode);
// //     }
// // }


// int main(){
//     // Create a player
//     //Player player("Player1");
//     //Player player2("Player2");
//     //Player player3("Player3");
//     // Create a board
//     //Board board;
//     //board.printBoard();
//     // Create a vector of players
//     //std::vector<Player> players;
//     // Add the player to the vector
//     //players.push_back(player);
//     //players.push_back(player2);
//     //players.push_back(player3);
//     // Roll the dice
//     //player.rollDice(players, board);
//     // get from the terminal the name of the first player


//     std::cout << "You can choose between the following colors: blue, green, red" << std::endl;
//     std::string name1;
//     std::cout << "Enter the name of the first player: ";
//     std::cin >> name1;
//     std::cout << "Choose a color for the player: ";
//     std::string color1;
//     std::cin >> color1;
//     // Create the first player
//     Player player1(name1, color1);
//     std::string colorCode1;
//     if (color1 == "blue") {
//         colorCode1 = "\033[1;34m";
//     } else if (color1 == "green") {
//         colorCode1 = "\033[1;32m";
//     } else if (color1 == "red") {
//         colorCode1 = "\033[1;31m";
//     }
//     std::cout << colorCode1 << "Player 1: " << name1 << "\033[0m" << std::endl;

//     std::string name2;
//     std::cout << "Enter the name of the second player: ";
//     std::cin >> name2;
//     std::cout << "Choose a color for the player: ";
//     std::string color2;
//     std::cin >> color2;
//     // Create the second player
//     Player player2(name2, color2);
//     std::string colorCode2;
//     if (color2 == "blue") {
//         colorCode2 = "\033[1;34m";
//     } else if (color2 == "green") {
//         colorCode2 = "\033[1;32m";
//     } else if (color2 == "red") {
//         colorCode2 = "\033[1;31m";
//     }
//     std::cout << colorCode2 << "Player 2: " << name2 << "\033[0m" << std::endl;

//     std::string name3;
//     std::cout << "Enter the name of the third player: ";
//     std::cin >> name3;
//     std::cout << "Choose a color for the player: ";
//     std::string color3;
//     std::cin >> color3;
//     // Create the third player
//     Player player3(name3, color3);
//     std::string colorCode3;
//     if (color3 == "blue") {
//         colorCode3 = "\033[1;34m";
//     } else if (color3 == "green") {
//         colorCode3 = "\033[1;32m";
//     } else if (color3 == "red") {
//         colorCode3 = "\033[1;31m";
//     }
//     std::cout << colorCode3 << "Player 3: " << name3 << "\033[0m" << std::endl;

//     // Add the players to the vector
//     std::vector<Player> players;
//     players.push_back(player1);
//     players.push_back(player2);
//     players.push_back(player3);
//     // Create the board
//     Board board;
//     // Print the board
//     board.printBoard();

//     // ask the players to place their settlements and roads
//     // for (Player& player : players) {
//     //     std::cout << "Player " << player.getPlayerName() << " places one settlements and one roads" << std::endl;
//     //     std::vector<std::string> places;
//     //     std::vector<int> placesNum;
//     //     std::string place;
//     //     int placeNum;
//     //     for (int i = 0; i < 2; ++i) {
//     //         std::cout << "Enter the number of the vertex you want to put their the settlement: ";
//     //         std::cin >> place;
//     //         places.push_back(place);
//     //         std::cout << "Enter the number of the edge you want to put their the road: ";
//     //         std::cin >> placeNum;
//     //         placesNum.push_back(placeNum);
//     //     }
//     //     player.placeSettlement(places, placesNum, board);
//     //     player.placeRoad(places, placesNum, board);
//     // }

//     // // Change the color of the vertex and the edge
//     // std::string colorCode;
//     // if(player1.getColor() == "blue"){
//     //     colorCode = "\033[1;34m";
//     // } else if(player1.getColor() == "green"){
//     //     colorCode = "\033[1;32m";
//     // } else if(player1.getColor() == "red"){
//     //     colorCode = "\033[1;31m";
//     // }


//     // if(player2.getColor() == "blue"){
//     //     colorCode = "\033[1;34m";
//     // } else if(player2.getColor() == "green"){
//     //     colorCode = "\033[1;32m";
//     // } else if(player2.getColor() == "red"){
//     //     colorCode = "\033[1;31m";
//     // }


//     // if(player3.getColor() == "blue"){
//     //     colorCode = "\033[1;34m";
//     // } else if(player3.getColor() == "green"){
//     //     colorCode = "\033[1;32m";
//     // } else if(player3.getColor() == "red"){
//     //     colorCode = "\033[1;31m";
//     // }


//     for(Player& player : players){
//         std::cout << "Player " << player.getPlayerName() << " places one settlements and one roads" << std::endl;
//         std::vector<std::string> places;
//         std::vector<int> placesNum;
//         std::string place;
//         int placeNum;
//         for (int i = 0; i < 2; ++i) {
//             std::cout << "Enter the number of the vertex you want to put their the settlement: ";
//             std::cin >> place;
//             places.push_back(place);
//             std::cout << "Enter the number of the edge you want to put their the road: ";
//             std::cin >> placeNum;
//             placesNum.push_back(placeNum);
//         }
//         player.placeSettlement(places, placesNum, board);
//         player.placeRoad(places, placesNum, board);

//         std::string colorCode;
//         if(player.getColor() == "blue"){
//             colorCode = "\033[1;34m";
//         } else if(player.getColor() == "green"){
//             colorCode = "\033[1;32m";
//         } else if(player.getColor() == "red"){
//             colorCode = "\033[1;31m";
//         }

//         for(const Vertex& vertex : player.placeSettlement()){
//             //board.setSettlementState(vertex.getId(), colorCode);
//             board.placeSettlement(vertex.getId());
//             board.setColor(vertex.getId(), colorCode);
//         }
//         // player.placeSettlement(places, placesNum, board);
//         // for(const Vertex& vertex : board.boardVertex){
//         //    // if(vertex.owner == player.id)
//         //    board.placeSettlement(vertex.getId());
//         //    board.setColor(vertex.getId(),colorCode);
//         // }


//         for(const Vertex& vertex : player.placeCity()){
//             //board.setCityState(vertex.getId(), colorCode);
//             board.placeCity(vertex.getId());
//             board.setColor(vertex.getId(), colorCode);
//         }

        
//         for(const Edge& edge : player.placeRoad()){
//             //board.setRoadState(edge.getId(), colorCode);
//             board.placeRoad(edge.getId());
//             board.setColor(edge.getId(), colorCode);
//         }
//         board.printBoard();
//     }

//     return 0;
// }


    #include <iostream>
    #include <string>
    #include "player.hpp"
    #include "board.hpp"
    #include "catan.hpp"


    int main(){
        //Create a player
        Player player1("Player1");
        Player player2("Player2");
        Player player3("Player3");

        Catan catan(player1, player2, player3);

        //Create a board
        Board board;
        board.printBoard();
        //Create a vector of players
        std::vector<Player> players;
        //Add the player to the vector
        players.push_back(player1);
        players.push_back(player2);
        players.push_back(player3);

        std::cout << "The players are: " ;
        for(Player& player : players){
            std::cout << player.getPlayerName() << " ";
        }
        std::cout << std::endl;

        // Place the first 2 settlements for each player
        int ver1 = 29;
        player1.placeSettlement(board, ver1);
        int edge1 = 41;
        player1.placeRoad(board, edge1);

        int ver2 = 40;
        player2.placeSettlement(board, ver2);
        int edge2 = 56;
        player2.placeRoad(board, edge2);

        int ver3 = 13;
        player3.placeSettlement(board, ver3);
        int edge3 = 15;
        player3.placeRoad(board, edge3);

        int ver33 = 42;
        player3.placeSettlement(board,ver33);
        int edge33 = 58;
        player3.placeRoad(board,edge33);
        players[2].resources.stone += 1;
        players[2].resources.wheat += 2;

        int ver22 = 44;
        player2.placeSettlement(board,ver22);
        int edge22 = 52;
        player2.placeRoad(board,edge22);
        players[1].resources.wheat += 1;
        players[1].resources.sheep += 2;

        int ver11 = 10;
        player1.placeSettlement(board,ver11);
        int edge11 = 13;
        player1.placeRoad(board, edge11);
        players[0].resources.stone += 1;
        players[0].resources.sheep += 1;
        players[0].resources.brick += 1;


        std::cout << "Player1 resources - wood: " << players[0].resources.wood << ", brick: " << players[0].resources.brick << ", sheep: " << players[0].resources.sheep << ", wheat: " << players[0].resources.wheat << ", stone: " << players[0].resources.stone << std::endl;
        std::cout << "Player2 resources - wood: " << players[1].resources.wood << ", brick: " << players[1].resources.brick << ", sheep: " << players[1].resources.sheep << ", wheat: " << players[1].resources.wheat << ", stone: " << players[1].resources.stone << std::endl;
        std::cout << "Player3 resources - wood: " << players[2].resources.wood << ", brick: " << players[2].resources.brick << ", sheep: " << players[2].resources.sheep << ", wheat: " << players[2].resources.wheat << ", stone: " << players[2].resources.stone << std::endl;


        std::cout << " ~~~~~~~~~" << std::endl;
        std::cout << "The game start" << std::endl;
        std::cout << " ~~~~~~~~~" << std::endl;

        // The first player
        player1.rollDice(players, board); // 7
        player1.rollDice(players,board); // 6
        player1.endTurn();

        std::cout << "Player1 resources - wood: " << players[0].resources.wood << ", brick: " << players[0].resources.brick << ", sheep: " << players[0].resources.sheep << ", wheat: " << players[0].resources.wheat << ", stone: " << players[0].resources.stone << std::endl;
        std::cout << "Player2 resources - wood: " << players[1].resources.wood << ", brick: " << players[1].resources.brick << ", sheep: " << players[1].resources.sheep << ", wheat: " << players[1].resources.wheat << ", stone: " << players[1].resources.stone << std::endl;
        std::cout << "Player3 resources - wood: " << players[2].resources.wood << ", brick: " << players[2].resources.brick << ", sheep: " << players[2].resources.sheep << ", wheat: " << players[2].resources.wheat << ", stone: " << players[2].resources.stone << std::endl;


        // The second player
        player2.rollDice(players, board); // 8
        player2.trade(player1,"wheat", 1,"brick", 1);
        int edge_2_63 = 63;
        player2.placeRoad(board, edge_2_63);
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 6
        player3.trade(player2,"wheat" , 1, "sheep", 1);
        player3.buyDevelopmentCard();
        player3.endTurn();

        // The first player
        player1.rollDice(players, board); // 6
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 5
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 5
        player3.endTurn();

        // The first player
        player1.rollDice(players, board); // 11
        int edge_1_20 = 20;
        player1.placeRoad(board,edge_1_20);
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 2
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 10
        player3.endTurn();
        
        // The first player
        player1.rollDice(players, board); // 9
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 8
        int ver_2_49 = 49;
        player2.placeSettlement(board,ver_2_49);
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 6
        int edg_3_21 = 21;
        player3.placeRoad(board,edg_3_21);
        player3.endTurn();

        // The first player
        player1.rollDice(players, board); // 5
        int ver_1_21 = 21;
        player1.placeSettlement(board,ver_1_21);
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 4
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 7
        player2.throwHalf(player2.cardsBuy);
        player3.rollDice(players, board); // 2
        player3.trade(player1,"wheat", 1, "stone", 1);
        player3.buyDevelopmentCard();
        player3.endTurn();

        // The first player
        player1.rollDice(players, board); // 10
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 7
        player2.rollDice(players, board); // 7
        player2.rollDice(players, board); // 8
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 10
        player3.trade(player1, "wheat", 1 , "wood", 1);
        player3.trade(player2, "wheat", 1, "wood", 1);
        int edge_3_30 = 30;
        player3.placeRoad(board, edge_3_30);
        player3.trade(player1, "wheat", 1, "sheep", 1);
        int ver_3_24 = 24;
        player3.placeSettlement(board, ver_3_24);
        player3.endTurn();

        // The first player
        player1.rollDice(players, board); // 5
        int ver_1_29 = 29;
        player1.placeCity(board, ver_1_29);
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 6
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 7
        player2.throwHalf(player2.cardsBuy);
        player3.rollDice(players, board); // 11

        // The first player
        player1.rollDice(players, board); // 5
        player1.trade(player3, "wood", 1, "wheat", 1);
        int edge_1_42 = 42;
        player1.placeRoad(board, edge_1_42);
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 7
        player2.throwHalf(player2.cardsBuy);
        player2.rollDice(players, board); // 6
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 7
        player3.rollDice(players, board); // 8
        player3.endTurn();

        // The first player
        player1.rollDice(players, board); // 7
        player1.throwHalf(player1.cardsBuy);
        player1.rollDice(players, board); // 9
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 9
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 8
        player3.trade(player2,"wood", 1, "wheat", 1);
        player3.endTurn();

        // The first player
        player1.rollDice(players, board); // 5
        int ver_1_31 = 31;
        player1.placeSettlement(board, ver_1_31);
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 5
        int edge_2_46 = 46;
        player2.placeRoad(board, edge_2_46);
        int edge_2_47 = 47;
        player2.placeRoad(board, edge_2_47);
        int ver_2_36 = 36;
        player2.placeSettlement(board, ver_2_36);
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 7
        player3.rollDice(players, board); // 6
        player3.endTurn();

        // The first player
        player1.rollDice(players, board); // 7
        player1.throwHalf(player1.cardsBuy);
        player1.rollDice(players, board); // 3
        player1.trade(player3,"wheat", 1, "wood", 1);
        int edge_1_12 = 12;
        player1.placeRoad(board, edge_1_12);
        player1.endTurn();

        // The second player
        player2.rollDice(players, board); // 4
        player2.buyDevelopmentCard();
        player2.endTurn();

        // The third player
        player3.rollDice(players, board); // 4
        int ver_3_13 = 13;
        player3.placeCity(board, ver_3_13);
        player3.endTurn();
    
    std::cout << "Player1 resources - wood: " << players[0].resources.wood << ", brick: " << players[0].resources.brick << ", sheep: " << players[0].resources.sheep << ", wheat: " << players[0].resources.wheat << ", stone: " << players[0].resources.stone << std::endl;
        std::cout << "Player2 resources - wood: " << players[1].resources.wood << ", brick: " << players[1].resources.brick << ", sheep: " << players[1].resources.sheep << ", wheat: " << players[1].resources.wheat << ", stone: " << players[1].resources.stone << std::endl;
        std::cout << "Player3 resources - wood: " << players[2].resources.wood << ", brick: " << players[2].resources.brick << ", sheep: " << players[2].resources.sheep << ", wheat: " << players[2].resources.wheat << ", stone: " << players[2].resources.stone << std::endl;



        // the game is finish
        player1.printPoints();
        player2.printPoints();
        player3.printPoints();

        catan.printWinner();

        return 0;

    }


    // // The first player
    // player1.rollDice(players, board); // 10

    // // The second player
    // player2.rollDice(players, board); // 5

    // // The third player
    // player3.rollDice(players, board); // 2

    // // The first player
    // player1.rollDice(players, board); // 4

    // // The second player
    // player2.rollDice(players, board); // 7
    // player2.rollDice(players, board); // 6

    // // The third player
    // player3.rollDice(players, board); // 7
    // player3.rollDice(players, board); // 9

    // // The first player
    // player1.rollDice(players, board); // 8

    // // The second player
    // player2.rollDice(players, board); // 10

    // // The third player
    // player3.rollDice(players, board); // 9

    // // The first player
    // player1.rollDice(players, board); // 5

    // // The second player
    // player2.rollDice(players, board); // 8

    // // The third player
    // player3.rollDice(players, board); // 5
