#include "GameBoard.h"

#include <iostream>

GameBoard::GameBoard(){
    gameRow.assign(BOARD_SIZE, nullptr);
    board.assign(BOARD_SIZE, gameRow);
}

std::vector<std::vector<Tile*>> GameBoard::getBoard(){
    return this->board;
}

void GameBoard::addTile(int row, int col, Tile* tile){
    this->board[row][col] = tile;
}

int GameBoard::getSize(){
    return board.size();
}

void GameBoard::printBoard(){
    for (int row = 0; row < this->getSize(); row++){
        for (int col = 0; col < this->getSize(); col++){
            if (board[row][col] == NULL){
                std::cout << "|   ";
            }else{
                std::cout << "| " << board[row][col]->getLetter() << " ";
            }
        }
        std::cout << std::endl;
    }
}
