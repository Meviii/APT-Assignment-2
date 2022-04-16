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
        void removeTile(int row, int col, Tile* tile);
        std::map<char, int> boardRow = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6},
                                        {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13},
                                        {'O', 14}};
    private:

        std::vector<Tile*> gameRow;
        std::vector<std::vector<Tile*>> board;
};

#endif // GAMEBOARD_H