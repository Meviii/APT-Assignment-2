#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <vector>

#include "LinkedList.h"

#define BOARD_SIZE  15

class GameBoard {
    public:
        GameBoard();
        std::vector<std::vector<Tile*>> getBoard();
        void printBoard();
        void addTile(int row, int col, Tile* tile);
        int getSize();

    private:

        std::vector<Tile*> gameRow;
        std::vector<std::vector<Tile*>> board;
        std::vector<char> rows;
        std::vector<int> cols;
};

#endif // GAMEBOARD_H