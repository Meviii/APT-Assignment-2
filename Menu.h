#ifndef MENU_H
#define MENU_H

#include "Player.h"
#include "GameBoard.h"
#include "LinkedList.h"
#include "Tile.h"
#include "TileBag.h"
#include "Node.h"

#include <iostream>
#include <string>
#include <vector>


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

        bool isTwoPlayer();

    private:
        int choice;
        std::vector<Player*> players;
};

#endif // MENU_H