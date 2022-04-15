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
    std::cout << std::endl;
    char alpha[15] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
    std::cout << "    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  " << std::endl;

    for (int row = 0; row < (this->getSize()); row++){
        for (int col = 0; col < (this->getSize()); col++){
            if (board[row][col] != NULL){
                if (board[14][col]){
                    std::cout << "| " << board[row][col]->getLetter() << " |";
                }else if (board[0][col]){
                    std::cout << alpha[row] << " | " << board[row][col]->getLetter() << " ";
                }else if (!board[0][col] && !board[14][col]){
                    std::cout <<"| " << board[row][col]->getLetter() << " ";
                }
            }else if (board[row][col] == NULL){
                if (board[0][col]){
                    std::cout << alpha[row] << " |   ";
                }else if (board[14][col]){
                    std::cout << "|   |";
                }else if (!board[0][col] && !board[14][col]){
                    std::cout << "|   ";
                }
            }
        }
        std::cout << std::endl;
    }
}

bool GameBoard::isTileValid(int row, int col){
    return row < BOARD_SIZE && col < BOARD_SIZE && board[row][col] == NULL;
}

// for (int row = 0; row < (this->getSize()); row++){
//         for (int col = 0; col < (this->getSize()); col++){
//             if (board[row][col] == NULL){
//                 if (board[0][col]){
//                     std::cout << alpha[row] << " |   ";
//                 }
//                 // else if (board[14][col]){
//                 //     std::cout << "|   |";
//                 // }
//                 // else if (!board[0][row]){
//                 //     std::cout << "|   ";
//                 // }
//             }else if (board[row][col] != NULL){
//                 if (board[0][col]){
//                     std::cout << alpha[row] << " | " << board[row][col]->getLetter() << " ";
//                 }else if (board[14][col]){
//                     std::cout << "| " << board[row][col]->getLetter() << " |";
//                 }else if (!board[0][row]){
//                     std::cout << "| " << board[row][col]->getLetter() << " ";
//                 }
//             }
//         }
//         std::cout << std::endl;
//     }