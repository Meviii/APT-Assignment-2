#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <vector>
#include <array>

#include "LinkedList.h"
#include "TileBag.h"
#include "Player.h"

#define BOARD_SIZE  15

class GameBoard {
    public:
        GameBoard();
        std::vector<std::vector<Tile*>> getBoard();
        void printBoard();
        void addTile(int row, int col, Tile* tile);
        int getSize();
        bool isTileValid(int row, int col);
        bool isGameOver(TileBag* tb, std::vector<Player*> players);
        void checkWinner(std::vector<Player*> players);

    private:

        std::vector<Tile*> gameRow;
        std::vector<std::vector<Tile*>> board;
};

#endif // GAMEBOARD_H