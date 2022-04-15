#include "../GameBoard.h"
#include "../LinkedList.h"

#include <iostream>

int main(void){
    GameBoard* gb = new GameBoard();
    Tile* tl1 = new Tile('A', 1);
    // Tile* tl2 = new Tile('C', 1);
    // Tile* tl3 = new Tile('C', 1);
    // Tile* tl4 = new Tile('B', 1);
    // Tile* tl5 = new Tile('E', 1);

    gb->addTile(0,0,tl1);
    // gb->addTile(0,1,tl2);
    // gb->addTile(0,2,tl3);
    // gb->addTile(0,3,tl4);
    // gb->addTile(0,4,tl5);

    gb->printBoard();

    // std::vector<std::vector<char>> vec{ 
    //                         { '1', '2', '3'},
    //                         { '4', '5', '6'},
    //                         { '7', '8', '9'}};
    
    // vec[0][1] = 's';
    // for (int i = 0; i < 3; i++) {
    //     for (
    //         auto it = vec[i].begin();
    //         it != vec[i].end(); it++)
    //         std::cout << *it << " ";
    //     std::cout << std::endl;
    // }


}
