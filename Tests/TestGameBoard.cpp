#include "../GameBoard.h"
#include "../LinkedList.h"
#include "../TileBag.h"
#include "../Player.h"

#include <iostream>
#include <vector>
#include <array>

int main(void){
    GameBoard* gb = new GameBoard();
    gb->printBoard();

}

class TestGameBoard {

    public:
        TestGameBoard();
        std::vector<std::vector<Tile*>> testGetBoard();
        void testPrintBoard();
        void testAddTile(int row, int col, Tile* tile);
        int testGetSize();
        bool testIsTileValid(int row, int col);
        std::map<char, int> boardRow = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6},
                                        {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13},
                                        {'O', 14}};

    private:
        std::vector<Tile*> gameRow;
        std::vector<std::vector<Tile*>> board;
    
    
    TestGameBoard(){
        gameRow.assign(BOARD_SIZE, nullptr);
        board.assign(BOARD_SIZE, gameRow);

        for (int row = 0; row < (this->getSize()); row++){
            for (int col = 0; col < (this->getSize()); col++){
                Tile* tmp = new Tile(' ',0);
                board[row][col] = tmp;
            }
        }
    }

    std::vector<std::vector<Tile*>> testGetBoard(){
        return this->board;
    }

    void testAddTile(int row, int col, Tile* tile){
        this->board[row][col] = tile;
    }

    int testGetSize(){
        return board.size();
    }


    void testPrintBoard(){
        char alpha[15] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
        
        std::cout << "    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  " << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;

        for (int row = 0; row < getSize(); row++){
            std::cout << alpha[row] << " ";
            for (int col = 0; col < getSize(); col++){
                if (board[row][col] == nullptr){
                    std::cout << "| ";
                }else{
                    std::cout << "| " << board[row][col]->getLetter() << " ";
                }
            }
            std::cout << "|" << std::endl;
        }
    }

    bool testIsTileValid(int row, int col){ // Area checks, open tile check 
        return row < BOARD_SIZE && col < BOARD_SIZE && (board[row][col] == NULL || board[row][col]->getLetter() == ' ');
    }

        
    }
