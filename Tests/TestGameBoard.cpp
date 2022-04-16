#include "../GameBoard.h"
#include "../LinkedList.h"

#include <iostream>

int main(void){
    GameBoard* gb = new GameBoard();
    // Tile* init = new Tile(' ', 0);
    // Tile* init2 = new Tile(' ', 0);


    //Tile* tl1 = new Tile('A', 1);
    //Tile* tl2 = new Tile('C', 1);
    Tile* tl3 = new Tile('C', 1);
    Tile* tl4 = new Tile('B', 1);
    Tile* tl5 = new Tile('E', 1);

    // gb->addTile(0,0,init);
    // gb->addTile(14,14,init2);

    gb->printBoard();
    //gb->addTile(0,0,tl1);
    //gb->addTile(14,14,tl2);
    gb->addTile(1,1,tl3);
    gb->addTile(6,5,tl4);
    gb->addTile(12,4,tl5);
    
    gb->printBoard();

    // gb->addTile(0,1,tl2);
    // gb->addTile(0,2,tl3);
    // gb->addTile(0,3,tl4);
    // gb->addTile(0,4,tl5);

    std::cout << gb->isTileValid(0,0);

    //gb->isGameOver();
    //gb->checkWinner();
}
