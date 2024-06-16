#include <vector>
#include <string>
#include <iostream>
#include "board.hpp"
#include "edge.hpp"
#include "vertex.hpp"
#include "meshushe.hpp"



void Board::printBoard() {
    std::cout << "                v:1          v:3          v:5" << std::endl;
    std::cout << "               /   \\       /    \\       /     \\" << std::endl;
    std::cout << "            e:0     e:1   e:2    e:3  e:4     e:5" << std::endl;
    std::cout << "             /        \\  /        \\   /         \\" << std::endl;
    std::cout << "           v:0         v:2         v:4          v:6" << std::endl;
    std::cout << "            |           |           |            |" << std::endl;
    std::cout << "           e:6   🪨     e:7   🐑    e:8    🪵     e:9" << std::endl;
    std::cout << "            |    10     |     2     |      9     |" << std::endl;
    std::cout << "           v:8         v:10        v:12         v:14" << std::endl;
    std::cout << "          /  \\       /   \\        /   \\        /    \\" << std::endl;
    std::cout << "      e:10   e:11  e:12   e:13  e:14   e:15  e:16   e:17" << std::endl;
    std::cout << "       /        \\   /       \\   /        \\  /         \\" << std::endl;
    std::cout << "     v:7         v:9         v:11         v:13        v:15" << std::endl;
    std::cout << "      |           |           |            |           |" << std::endl;
    std::cout << "     e:18   🌾  e:19   🧱   e:20   🐑    e:21   🧱    e:22" << std::endl;
    std::cout << "      |     12    |     6     |     4      |    10     |" << std::endl;
    std::cout << "     v:17        v:19        v:21        v:23         v:25" << std::endl;
    std::cout << "    /   \\       /   \\      /    \\       /    \\       /   \\" << std::endl;
    std::cout << " e:23  e:24  e:25   e:26  e:27  e:28  e:29   e:30  e:31  e:32" << std::endl;
    std::cout << "  /       \\  /        \\  /        \\  /         \\  /        \\" << std::endl;
    std::cout << "v:16       v:18        v:20       v:22         v:24       v:26" << std::endl;
    std::cout << " |          |           |          |            |           |" << std::endl;
    std::cout << "e:33  🌾   e:34   🪵    e:35  🏜️    e:36   🪵    e:37   🪨     e:38" << std::endl;
    std::cout << " |     9    |     11    |          |      3     |     8     |" << std::endl;
    std::cout << "v:27       v:29        v:31       v:33         v:35        v:37" << std::endl;
    std::cout << "  \\      /   \\       /    \\      /    \\       /   \\       /" << std::endl;
    std::cout << " e:39  e:40  e:41   e:42  e:43  e:44  e:45  e:46   e:47  e:48" << std::endl;
    std::cout << "    \\  /        \\  /         \\ /         \\  /        \\  /" << std::endl;
    std::cout << "     v:28       v:30         v:32        v:34         v:36" << std::endl;
    std::cout << "      |           |           |           |            |" << std::endl;
    std::cout << "     e:49  🪵    e:50   🪨     e:51   🌾   e:52   🐑    e:53" << std::endl;
    std::cout << "      |     8     |     3     |      4    |      5     |" << std::endl;
    std::cout << "     v:38        v:40        v:42        v:44         v:46" << std::endl;
    std::cout << "       \\        /   \\       /   \\        /   \\        /" << std::endl;
    std::cout << "      e:54   e:55   e:56  e:57  e:58  e:59  e:60   e:61" << std::endl;
    std::cout << "         \\   /        \\   /        \\   /        \\   /" << std::endl;
    std::cout << "          v:39         v:41         v:43         v:45" << std::endl;
    std::cout << "           |            |            |            |" << std::endl;
    std::cout << "          e:62  🧱    e:63    🌾   e:64    🐑    e:65" << std::endl;
    std::cout << "           |     5      |      6     |      11    |" << std::endl;
    std::cout << "          v:47         v:49         v:51         v:53" << std::endl;
    std::cout << "           \\          /   \\        /    \\        /" << std::endl;
    std::cout << "           e:66     e:67  e:68   e:69   e:70   e:71" << std::endl;
    std::cout << "              \\     /        \\   /        \\   /" << std::endl;
    std::cout << "                v:48          v:50         v:52" << std::endl;
}

void Board::initialize(){
    int numbers[19] = {10,2,9,12,6,4,10,9,11,7,3,8,8,3,4,5,5,6,11}; // The arrangement of numbers on the board is the same, but the order of the resources is the one that changes
    std::string resource[19] = {"stone","sheep","wood", "wheat","brick","sheep","brick","wheat","wood", "desert", "wood", "stone","wood", "stone","wheat", "sheep", "brick", "wheat", "sheep"};
    // להגדיר כל משושה עם צלעות וקודקודים לפי המספרים והמשאבים שעליה
   

    Vertex vertices1[6] = {
        Vertex(0), Vertex(1), Vertex(2), Vertex(8), Vertex(9), Vertex(10)
    };
    Meshushe mesh1(10,"rock",vertices1);
    Vertex vertices2[6] = {
        Vertex(2), Vertex(3), Vertex(4), Vertex(10), Vertex(11), Vertex(12)
    };
    meshushe[0] = mesh1;
    // Meshushe mesh2(2,"sheep",vertices2);
    // Vertex vertices3[6] = {
    //     Vertex(4), Vertex(5), Vertex(6), Vertex(12), Vertex(13), Vertex(14)
    // };
    // Meshushe mesh3(9,"wood",vertices3);
    // Vertex vertices4[6] = {
    //     Vertex(7), Vertex(8), Vertex(9), Vertex(17), Vertex(18), Vertex(19)
    // };
    // Meshushe mesh4(12,"wheat",vertices4);
    // Vertex vertices5[6] = {
    //     Vertex(9), Vertex(10), Vertex(11), Vertex(19), Vertex(20), Vertex(21)
    // };
    // Meshushe mesh5(6,"brick",vertices5);
    // Vertex vertices6[6] = {
    //     Vertex(11), Vertex(12), Vertex(13), Vertex(21), Vertex(22), Vertex(23)
    // };
    // Meshushe mesh6(4,"sheep",vertices6);
    // Vertex vertices7[6] = {
    //     Vertex(13), Vertex(14), Vertex(15), Vertex(23), Vertex(24), Vertex(25)
    // };
    // Meshushe mesh7(10,"brick",vertices7);
    // Vertex vertices8[6] = {
    //     Vertex(16), Vertex(17), Vertex(18), Vertex(27), Vertex(28), Vertex(29)
    // };
    // Meshushe mesh8(9,"wheat",vertices8);
    // Vertex vertices9[6] = {
    //     Vertex(18), Vertex(19), Vertex(20), Vertex(29), Vertex(30), Vertex(31)
    // };
    // Meshushe mesh9(11,"wood",vertices9);
    // Vertex vertices10[6] = {
    //     Vertex(20), Vertex(21), Vertex(22), Vertex(31), Vertex(32), Vertex(33)
    // };
    // Meshushe mesh10(7,"desert",vertices10);
    // Vertex vertices11[6] = {
    //     Vertex(22), Vertex(23), Vertex(24), Vertex(33), Vertex(34), Vertex(35)
    // };
    // Meshushe mesh11(3,"wood",vertices11);
    // Vertex vertices12[6] = {
    //     Vertex(24), Vertex(25), Vertex(26), Vertex(35), Vertex(36), Vertex(37)
    // };
    // Meshushe mesh12(8,"rock",vertices12);
    // Vertex vertices13[6] = {
    //     Vertex(28), Vertex(29), Vertex(30), Vertex(38), Vertex(39), Vertex(40)
    // };
    // Meshushe mesh13(8,"wood",vertices13);
    // Vertex vertices14[6] = {
    //     Vertex(30), Vertex(31), Vertex(32), Vertex(40), Vertex(41), Vertex(42)
    // };
    // Meshushe mesh14(3,"rock",vertices14);
    // Vertex vertices15[6] = {
    //     Vertex(32), Vertex(33), Vertex(34), Vertex(42), Vertex(43), Vertex(44)
    // };
    // Meshushe mesh15(4,"wheat",vertices15);
    // Vertex vertices16[6] = {
    //     Vertex(34), Vertex(35), Vertex(36), Vertex(44), Vertex(45), Vertex(46)
    // };
    // Meshushe mesh16(5,"sheep",vertices16);
    // Vertex vertices17[6] = {
    //     Vertex(39), Vertex(40), Vertex(41), Vertex(47), Vertex(48), Vertex(49)
    // };
    // Meshushe mesh17(5,"brick",vertices17);
    // Vertex vertices18[6] = {
    //     Vertex(41), Vertex(42), Vertex(43), Vertex(49), Vertex(50), Vertex(51)
    // };
    // Meshushe mesh18(6,"wheat",vertices18);
    // Vertex vertices19[6] = {
    //     Vertex(43), Vertex(44), Vertex(45), Vertex(51), Vertex(52), Vertex(53)
    // };
    // Meshushe mesh19(11,"sheep",vertices19);


    // meshushe[0] = mesh1;
    // meshushe[1] = mesh2;
    // meshushe[2] = mesh3;
    // meshushe[3] = mesh4;
    // meshushe[4] = mesh5;
    // meshushe[5] = mesh6;
    // meshushe[6] = mesh7;
    // meshushe[7] = mesh8;
    // meshushe[8] = mesh9;
    // meshushe[9] = mesh10;
    // meshushe[10] = mesh11;
    // meshushe[11] = mesh12;
    // meshushe[12] = mesh13;
    // meshushe[13] = mesh14;
    // meshushe[14] = mesh15;
    // meshushe[15] = mesh16;
    // meshushe[16] = mesh17;
    // meshushe[17] = mesh18;
    // meshushe[18] = mesh19;
    // // Define the resources of every mesh

    

}


void Board::defineEdgeAndVertex(){
    // Define the neighbor of every edge
    boardedge[0].edge_neighbor_edge = {1,6};
    boardedge[1].edge_neighbor_edge = {0,2,7};
    boardedge[2].edge_neighbor_edge = {1,3,7};
    boardedge[3].edge_neighbor_edge = {2,4,8};
    boardedge[4].edge_neighbor_edge = {3,5,8};
    boardedge[5].edge_neighbor_edge = {4,9};
    boardedge[6].edge_neighbor_edge = {0,10,11};
    boardedge[7].edge_neighbor_edge = {1,2,12,13};
    boardedge[8].edge_neighbor_edge = {3,4,14,15};
    boardedge[9].edge_neighbor_edge = {5,16,17};
    boardedge[10].edge_neighbor_edge = {6,11,18};
    boardedge[11].edge_neighbor_edge = {6,10,12,19};
    boardedge[12].edge_neighbor_edge = {7,11,13,19};
    boardedge[13].edge_neighbor_edge = {7,12,14,20};
    boardedge[14].edge_neighbor_edge = {8,13,15,20};
    boardedge[15].edge_neighbor_edge = {8,14,16,21};
    boardedge[16].edge_neighbor_edge = {9,15,17,21};
    boardedge[17].edge_neighbor_edge = {9,16,22};
    boardedge[18].edge_neighbor_edge = {10,23,24};
    boardedge[19].edge_neighbor_edge = {11,12,25,26};
    boardedge[20].edge_neighbor_edge = {13,14,27,28};
    boardedge[21].edge_neighbor_edge = {15,16,29,30};
    boardedge[22].edge_neighbor_edge = {17,31,32};
    boardedge[23].edge_neighbor_edge = {18,24,33};
    boardedge[24].edge_neighbor_edge = {18,23,25,34};
    boardedge[25].edge_neighbor_edge = {19,24,26,34};
    boardedge[26].edge_neighbor_edge = {19,25,27,35};
    boardedge[27].edge_neighbor_edge = {20,26,28,35};
    boardedge[28].edge_neighbor_edge = {20,27,29,36};
    boardedge[29].edge_neighbor_edge = {21,28,30,36};
    boardedge[30].edge_neighbor_edge = {21,29,31,37};
    boardedge[31].edge_neighbor_edge = {22,30,37,32};
    boardedge[32].edge_neighbor_edge = {22,31,38};
    boardedge[33].edge_neighbor_edge = {23,39};
    boardedge[34].edge_neighbor_edge = {24,25,40,41};
    boardedge[35].edge_neighbor_edge = {26,27,42,43};
    boardedge[36].edge_neighbor_edge = {28,29,44,45};
    boardedge[37].edge_neighbor_edge = {30,31,46,47};
    boardedge[38].edge_neighbor_edge = {32,48};
    boardedge[39].edge_neighbor_edge = {33,40,49};
    boardedge[40].edge_neighbor_edge = {34,39,41,49};
    boardedge[41].edge_neighbor_edge = {34,40,42,50};
    boardedge[42].edge_neighbor_edge = {35,41,43,50};
    boardedge[43].edge_neighbor_edge = {35,42,44,51};
    boardedge[44].edge_neighbor_edge = {36,43,45,51};
    boardedge[45].edge_neighbor_edge = {36,44,46,52};
    boardedge[46].edge_neighbor_edge = {37,45,47,52};
    boardedge[47].edge_neighbor_edge = {37,46,48,53};
    boardedge[48].edge_neighbor_edge = {38,47,53};
    boardedge[49].edge_neighbor_edge = {39,40,54};
    boardedge[50].edge_neighbor_edge = {41,42,55,56};
    boardedge[51].edge_neighbor_edge = {43,44,57,58};
    boardedge[52].edge_neighbor_edge = {45,46,59,60};
    boardedge[53].edge_neighbor_edge = {47,48,61};
    boardedge[54].edge_neighbor_edge = {49,55,62};
    boardedge[55].edge_neighbor_edge = {50,54,56,62};
    boardedge[56].edge_neighbor_edge = {50,55,57,63};
    boardedge[57].edge_neighbor_edge = {51,56,58,63};
    boardedge[58].edge_neighbor_edge = {51,57,59,64};
    boardedge[59].edge_neighbor_edge = {52,58,60,64};
    boardedge[60].edge_neighbor_edge = {52,59,61,65};
    boardedge[61].edge_neighbor_edge = {53,60,65};
    boardedge[62].edge_neighbor_edge = {54,55,66};
    boardedge[63].edge_neighbor_edge = {56,57,67,68};
    boardedge[64].edge_neighbor_edge = {58,59,69,70};
    boardedge[65].edge_neighbor_edge = {60,61,71};
    boardedge[66].edge_neighbor_edge = {62,67};
    boardedge[67].edge_neighbor_edge = {63,66,68};
    boardedge[68].edge_neighbor_edge = {63,67,69};
    boardedge[69].edge_neighbor_edge = {64,68,70};
    boardedge[70].edge_neighbor_edge = {64,69,71};
    boardedge[71].edge_neighbor_edge = {65,70};
    
    // Define the neighbor of each vertex
    boardVertex[0].vertex_neighbor_vertex = {1,8};
    boardVertex[1].vertex_neighbor_vertex = {0,2};
    boardVertex[2].vertex_neighbor_vertex = {1,3,10};
    boardVertex[3].vertex_neighbor_vertex = {2,4};
    boardVertex[4].vertex_neighbor_vertex = {3,5,12};
    boardVertex[5].vertex_neighbor_vertex = {4,6};
    boardVertex[6].vertex_neighbor_vertex = {5,14};
    boardVertex[7].vertex_neighbor_vertex = {8,17};
    boardVertex[8].vertex_neighbor_vertex = {0,7,9};
    boardVertex[9].vertex_neighbor_vertex = {8,10,19};
    boardVertex[10].vertex_neighbor_vertex = {2,9,11};
    boardVertex[11].vertex_neighbor_vertex = {10,12,21};
    boardVertex[12].vertex_neighbor_vertex = {4,11,13};
    boardVertex[13].vertex_neighbor_vertex = {12,14,23};
    boardVertex[14].vertex_neighbor_vertex = {6,13,15};
    boardVertex[15].vertex_neighbor_vertex = {14,25};
    boardVertex[16].vertex_neighbor_vertex = {17,27};
    boardVertex[17].vertex_neighbor_vertex = {7,16,18};
    boardVertex[18].vertex_neighbor_vertex = {17,19,29};
    boardVertex[19].vertex_neighbor_vertex = {9,18,20};
    boardVertex[20].vertex_neighbor_vertex = {19,21,31};
    boardVertex[21].vertex_neighbor_vertex = {11,20,22};
    boardVertex[22].vertex_neighbor_vertex = {21,23,33};
    boardVertex[23].vertex_neighbor_vertex = {13,22,24};
    boardVertex[24].vertex_neighbor_vertex = {23,25,35};
    boardVertex[25].vertex_neighbor_vertex = {15,24,26};
    boardVertex[26].vertex_neighbor_vertex = {25,37};
    boardVertex[27].vertex_neighbor_vertex = {16,28};
    boardVertex[28].vertex_neighbor_vertex = {27,29,38};
    boardVertex[29].vertex_neighbor_vertex = {18,28,30};
    boardVertex[30].vertex_neighbor_vertex = {29,31,40};
    boardVertex[31].vertex_neighbor_vertex = {20,30,32};
    boardVertex[32].vertex_neighbor_vertex = {31,33,42};
    boardVertex[33].vertex_neighbor_vertex = {22,32,34};
    boardVertex[34].vertex_neighbor_vertex = {33,35,44};
    boardVertex[35].vertex_neighbor_vertex = {24,34,36};
    boardVertex[36].vertex_neighbor_vertex = {35,37,46};
    boardVertex[37].vertex_neighbor_vertex = {26,36};
    boardVertex[38].vertex_neighbor_vertex = {28,39};
    boardVertex[39].vertex_neighbor_vertex = {38,40,47};
    boardVertex[40].vertex_neighbor_vertex = {30,39,41};
    boardVertex[41].vertex_neighbor_vertex = {40,42,49};
    boardVertex[42].vertex_neighbor_vertex = {32,41,43};
    boardVertex[43].vertex_neighbor_vertex = {42,44,51};
    boardVertex[44].vertex_neighbor_vertex = {34,43,45};
    boardVertex[45].vertex_neighbor_vertex = {44,46,53};
    boardVertex[46].vertex_neighbor_vertex = {36,45};
    boardVertex[47].vertex_neighbor_vertex = {39,48};
    boardVertex[48].vertex_neighbor_vertex = {47,49};
    boardVertex[49].vertex_neighbor_vertex = {41,48,50};
    boardVertex[50].vertex_neighbor_vertex = {49,51};
    boardVertex[51].vertex_neighbor_vertex = {43,50,52};
    boardVertex[52].vertex_neighbor_vertex = {51,53};
    boardVertex[53].vertex_neighbor_vertex = {45,52};

    // Define the vertex neighbor of every edge
    boardedge[0].edge_neighbor_vertex = {0,1};
    boardedge[1].edge_neighbor_vertex = {1,2};
    boardedge[2].edge_neighbor_vertex = {2,3};
    boardedge[3].edge_neighbor_vertex = {3,4};
    boardedge[4].edge_neighbor_vertex = {4,5};
    boardedge[5].edge_neighbor_vertex = {5,6};
    boardedge[6].edge_neighbor_vertex = {0,8};
    boardedge[7].edge_neighbor_vertex = {2,10};
    boardedge[8].edge_neighbor_vertex = {4,12};
    boardedge[9].edge_neighbor_vertex = {6,14};
    boardedge[10].edge_neighbor_vertex = {7,8};
    boardedge[11].edge_neighbor_vertex = {8,9};
    boardedge[12].edge_neighbor_vertex = {9,10};
    boardedge[13].edge_neighbor_vertex = {10,11};
    boardedge[14].edge_neighbor_vertex = {11,12};
    boardedge[15].edge_neighbor_vertex = {12,13};
    boardedge[16].edge_neighbor_vertex = {13,14};
    boardedge[17].edge_neighbor_vertex = {14,15};
    boardedge[18].edge_neighbor_vertex = {7,17};
    boardedge[19].edge_neighbor_vertex = {9,19};
    boardedge[20].edge_neighbor_vertex = {11,21};
    boardedge[21].edge_neighbor_vertex = {13,23};
    boardedge[22].edge_neighbor_vertex = {15,25};
    boardedge[23].edge_neighbor_vertex = {16,17};
    boardedge[24].edge_neighbor_vertex = {17,18};
    boardedge[25].edge_neighbor_vertex = {18,19};
    boardedge[26].edge_neighbor_vertex = {19,20};
    boardedge[27].edge_neighbor_vertex = {20,21};
    boardedge[28].edge_neighbor_vertex = {21,22};
    boardedge[29].edge_neighbor_vertex = {22,23};
    boardedge[30].edge_neighbor_vertex = {23,24};
    boardedge[31].edge_neighbor_vertex = {24,25};
    boardedge[32].edge_neighbor_vertex = {25,26};
    boardedge[33].edge_neighbor_vertex = {16,27};
    boardedge[34].edge_neighbor_vertex = {18,29};
    boardedge[35].edge_neighbor_vertex = {20,31};
    boardedge[36].edge_neighbor_vertex = {22,33};
    boardedge[37].edge_neighbor_vertex = {24,35};
    boardedge[38].edge_neighbor_vertex = {26,37};
    boardedge[39].edge_neighbor_vertex = {27,28};
    boardedge[40].edge_neighbor_vertex = {28,29};
    boardedge[41].edge_neighbor_vertex = {29,30};
    boardedge[42].edge_neighbor_vertex = {30,31};
    boardedge[43].edge_neighbor_vertex = {31,32};
    boardedge[44].edge_neighbor_vertex = {32,33};
    boardedge[45].edge_neighbor_vertex = {33,34};
    boardedge[46].edge_neighbor_vertex = {34,35};
    boardedge[47].edge_neighbor_vertex = {35,36};
    boardedge[48].edge_neighbor_vertex = {36,37};
    boardedge[49].edge_neighbor_vertex = {28,38};
    boardedge[50].edge_neighbor_vertex = {30,40};
    boardedge[51].edge_neighbor_vertex = {32,42};
    boardedge[52].edge_neighbor_vertex = {34,44};
    boardedge[53].edge_neighbor_vertex = {36,46};
    boardedge[54].edge_neighbor_vertex = {38,39};
    boardedge[55].edge_neighbor_vertex = {39,40};
    boardedge[56].edge_neighbor_vertex = {40,41};
    boardedge[57].edge_neighbor_vertex = {41,42};
    boardedge[58].edge_neighbor_vertex = {42,43};
    boardedge[59].edge_neighbor_vertex = {43,44};
    boardedge[60].edge_neighbor_vertex = {44,45};
    boardedge[61].edge_neighbor_vertex = {45,46};
    boardedge[62].edge_neighbor_vertex = {39,47};
    boardedge[63].edge_neighbor_vertex = {41,49};
    boardedge[64].edge_neighbor_vertex = {43,51};
    boardedge[65].edge_neighbor_vertex = {45,53};
    boardedge[66].edge_neighbor_vertex = {47,48};
    boardedge[67].edge_neighbor_vertex = {48,49};
    boardedge[68].edge_neighbor_vertex = {49,50};
    boardedge[69].edge_neighbor_vertex = {50,51};
    boardedge[70].edge_neighbor_vertex = {51,52};
    boardedge[71].edge_neighbor_vertex = {52,53};
    
    // Define the edge neighbor of every vertax
    boardVertex[0].vertex_neighbor_edge = {0,6};
    boardVertex[1].vertex_neighbor_edge = {0,1};
    boardVertex[2].vertex_neighbor_edge = {1,2,7};
    boardVertex[3].vertex_neighbor_edge = {2,3};
    boardVertex[4].vertex_neighbor_edge = {3,4,8};
    boardVertex[5].vertex_neighbor_edge = {4,5};
    boardVertex[6].vertex_neighbor_edge = {5,9};
    boardVertex[7].vertex_neighbor_edge = {10,18};
    boardVertex[8].vertex_neighbor_edge = {6,10,11};
    boardVertex[9].vertex_neighbor_edge = {11,12,19};
    boardVertex[10].vertex_neighbor_edge = {7,12,13};
    boardVertex[11].vertex_neighbor_edge = {13,14,20};
    boardVertex[12].vertex_neighbor_edge = {8,14,15};
    boardVertex[13].vertex_neighbor_edge = {15,16,21};
    boardVertex[14].vertex_neighbor_edge = {9,16,17};
    boardVertex[15].vertex_neighbor_edge = {17,22};
    boardVertex[16].vertex_neighbor_edge = {23,33};
    boardVertex[17].vertex_neighbor_edge = {18,23,24};
    boardVertex[18].vertex_neighbor_edge = {24,25,34};
    boardVertex[19].vertex_neighbor_edge = {19,25,26};
    boardVertex[20].vertex_neighbor_edge = {26,27,35};
    boardVertex[21].vertex_neighbor_edge = {20,27,28};
    boardVertex[22].vertex_neighbor_edge = {28,29,36};
    boardVertex[23].vertex_neighbor_edge = {21,29,30};
    boardVertex[24].vertex_neighbor_edge = {30,31,37};
    boardVertex[25].vertex_neighbor_edge = {22,31,32};
    boardVertex[26].vertex_neighbor_edge = {32,38};
    boardVertex[27].vertex_neighbor_edge = {33,39};
    boardVertex[28].vertex_neighbor_edge = {39,40,49};
    boardVertex[29].vertex_neighbor_edge = {34,40,41};
    boardVertex[30].vertex_neighbor_edge = {41,42,50};
    boardVertex[31].vertex_neighbor_edge = {35,42,43};
    boardVertex[32].vertex_neighbor_edge = {43,44,51};
    boardVertex[33].vertex_neighbor_edge = {36,44,45};
    boardVertex[34].vertex_neighbor_edge = {45,46,52};
    boardVertex[35].vertex_neighbor_edge = {37,46,47};
    boardVertex[36].vertex_neighbor_edge = {47,48,53};
    boardVertex[37].vertex_neighbor_edge = {38,48};
    boardVertex[38].vertex_neighbor_edge = {49,54};
    boardVertex[39].vertex_neighbor_edge = {54,55,62};
    boardVertex[40].vertex_neighbor_edge = {50,55,56};
    boardVertex[41].vertex_neighbor_edge = {56,57,63};
    boardVertex[42].vertex_neighbor_edge = {51,57,58};
    boardVertex[43].vertex_neighbor_edge = {58,59,64};
    boardVertex[44].vertex_neighbor_edge = {52,59,60};
    boardVertex[45].vertex_neighbor_edge = {60,61,65};
    boardVertex[46].vertex_neighbor_edge = {53,61};
    boardVertex[47].vertex_neighbor_edge = {62,66};
    boardVertex[48].vertex_neighbor_edge = {66,67};
    boardVertex[49].vertex_neighbor_edge = {63,67,68};
    boardVertex[50].vertex_neighbor_edge = {68,69};
    boardVertex[51].vertex_neighbor_edge = {64,69,70};
    boardVertex[52].vertex_neighbor_edge = {70,71};
    boardVertex[53].vertex_neighbor_edge = {65,71};

}


bool Board::isEdgeEmpth(int edgeIndex) const{
    return boardedge[edgeIndex].isEmpty;
}

bool Board::isVertexEmpty(int vertexIndex) const{
    return boardVertex[vertexIndex].isEmpty;
}

void Board::placeSettlement(int vertexIndex){
    if(isVertexEmpty(vertexIndex)){
        boardVertex[vertexIndex].placeSettlement();
    } else {
        std::cout << "Cannot place settlement here. Vertex is not empty.\n" << std::endl;
    }
}

// void Board::placeSettlement(int vertexIndex){
//     boardVertex[vertexIndex].placeSettlement();
// }

void Board::placeCity(int vertexIndex){
    boardVertex[vertexIndex].placeCity();
}

void Board::placeRoad(int edgeIndex){
    boardedge[edgeIndex].placeRoad();
}

void Board::setPointState(int vertexIndex, std::string color){
    boardVertex[vertexIndex].setColor(color);
}

void Board::setRoadState(int edgeIndex, std::string color){
    boardedge[edgeIndex].setColor(color);
}

void Board::setSettlementState(int vertexIndex, std::string color){
    boardVertex[vertexIndex].setColor(color);
}
void Board::setCityState(int vertexIndex, std::string color){
    boardVertex[vertexIndex].setColor(color);
}


void Board::setColor(int vertexIndex, std::string color){
    boardVertex[vertexIndex].setColor(color);
}

void Board::setVertex(int placeNum, std::string color){
    boardVertex[placeNum].setColor(color);
}

void Board::setVertex(int placeNum){
    boardVertex[placeNum].owner = 1;
}

void Board::setEdge(int placeNum){
    boardedge[placeNum].owner = 1;
}


 // int mesh1[6] = {0,1,2,8,9,10};
    // int mesh2[6] = {2,3,4,10,11,12};
    // int mesh3[6] = {4,5,6,12,13,14};
    // int mesh4[6] = {7,8,9,17,18,19};
    // int mesh5[6] = {9,10,11,19,20,21};
    // int mesh6[6] = {11,12,13,21,22,23};
    // int mesh7[6] = {13,14,15,23,24,25};
    // int mesh8[6] = {16,17,18,27,28,29};
    // int mesh9[6] = {18,19,20,29,30,31};
    // int mesh10[6] = {20,21,22,31,32,33};
    // int mesh11[6] = {22,23,24,33,34,35};
    // int mesh12[6] = {24,25,26,35,36,37};
    // int mesh13[6] = {28,29,30,38,39,40};
    // int mesh14[6] = {30,31,32,40,41,42};
    // int mesh15[6] = {32,33,34,42,43,44};
    // int mesh16[6] = {34,35,36,44,45,46};
    // int mesh17[6] = {39,40,41,47,48,49};
    // int mesh18[6] = {41,42,43,49,50,51};
    // int mesh19[6] = {43,44,45,51,52,53};

// void Board::printBoard() {
//     std::cout << "                v:1          v:3          v:5" << std::endl;
//     std::cout << "               /   \\       /    \\       /     \\" << std::endl;
//     std::cout << "            e:0     e:1   e:2    e:3  e:4     e:5" << std::endl;
//     std::cout << "             /        \\  /        \\   /         \\" << std::endl;
//     std::cout << "           v:0         v:2         v:4          v:6" << std::endl;
//     std::cout << "            |           |           |            |" << std::endl;
//     std::cout << "           e:6  stone   e:7  sheep  e:8   wood   e:9" << std::endl;
//     std::cout << "            |    10     |     2     |     9      |" << std::endl;
//     std::cout << "           v:8         v:10        v:12         v:14" << std::endl;
//     std::cout << "          /  \\       /   \\        /   \\        /    \\" << std::endl;
//     std::cout << "      e:10   e:11  e:12   e:13  e:14   e:15  e:16   e:17" << std::endl;
//     std::cout << "       /        \\   /       \\   /        \\  /         \\" << std::endl;
//     std::cout << "     v:7         v:9         v:11         v:13        v:15" << std::endl;
//     std::cout << "      |           |           |            |           |" << std::endl;
//     std::cout << "     e:18  wheat e:19 brick  e:20  sheep  e:21  brick e:22" << std::endl;
//     std::cout << "      |     12    |     6     |      4     |     10    |" << std::endl;
//     std::cout << "     v:17        v:19        v:21        v:23         v:25" << std::endl;
//     std::cout << "    /   \\       /   \\      /    \\       /    \\       /   \\" << std::endl;
//     std::cout << " e:23  e:24  e:25   e:26  e:27  e:28  e:29   e:30  e:31  e:32" << std::endl;
//     std::cout << "  /       \\  /        \\  /        \\  /         \\  /        \\" << std::endl;
//     std::cout << "v:16       v:18        v:20       v:22         v:24       v:26" << std::endl;
//     std::cout << " |          |           |          |            |           |" << std::endl;
//     std::cout << "e:33 wheat e:34  wood  e:35  🏜   e:36   wood  e:37  stone  e:38" << std::endl;
//     std::cout << " |     9    |     11    |          |      3     |     8     |" << std::endl;
//     std::cout << "v:27       v:29        v:31       v:33         v:35        v:37" << std::endl;
//     std::cout << "  \\      /   \\       /    \\      /    \\       /   \\       /" << std::endl;
//     std::cout << " e:39  e:40  e:41   e:42  e:43  e:44  e:45  e:46   e:47  e:48" << std::endl;
//     std::cout << "    \\  /        \\  /         \\ /         \\  /        \\  /" << std::endl;
//     std::cout << "     v:28       v:30         v:32        v:34         v:36" << std::endl;
//     std::cout << "      |           |           |           |            |" << std::endl;
//     std::cout << "     e:49  wood  e:50  stone  e:51  wheat e:52  sheep  e:53" << std::endl;
//     std::cout << "      |     8     |     3     |      4    |      5     |" << std::endl;
//     std::cout << "     v:38        v:40        v:42        v:44         v:46" << std::endl;
//     std::cout << "       \\        /   \\       /   \\        /   \\        /" << std::endl;
//     std::cout << "      e:54   e:55   e:56  e:57  e:58  e:59  e:60   e:61" << std::endl;
//     std::cout << "         \\   /        \\   /        \\   /        \\   /" << std::endl;
//     std::cout << "          v:39         v:41         v:43         v:45" << std::endl;
//     std::cout << "           |            |            |            |" << std::endl;
//     std::cout << "          e:62  brick  e:63  wheat  e:64  sheep  e:65" << std::endl;
//     std::cout << "           |      5     |      6     |     11     |" << std::endl;
//     std::cout << "          v:47         v:49         v:51         v:53" << std::endl;
//     std::cout << "           \\          /   \\        /    \\        /" << std::endl;
//     std::cout << "           e:66     e:67  e:68   e:69   e:70   e:71" << std::endl;
//     std::cout << "              \\     /        \\   /        \\   /" << std::endl;
//     std::cout << "                v:48          v:50         v:52" << std::endl;
// }
