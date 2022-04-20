#ifndef MENU_H
#define MENU_H

#include "Player.h"
#include "GameBoard.h"
#include "LinkedList.h"
#include "Tile.h"
#include "TileBag.h"
#include "Node.h"
#include "GameEngine.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <ctype.h>

class Menu {
    public:
        Menu();
        ~Menu();

        void runMenu();
        void printMenu();
        void runChoice();
        void printCredits();
        void playerSelection(int i);
        void playerCheck();
        void newGame();
        std::vector<std::string> argTokenizer(std::string input);
        int argCounter(std::string input);
        bool isTwoPlayer();
        void loadGame(std::string inputFile);
        
    private:
        int choice;
        std::vector<Player*> players;
};

#endif // MENU_H