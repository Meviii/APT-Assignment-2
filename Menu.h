#ifndef MENU_H
#define MENU_H

#include "Player.h"

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
        bool isTwoPlayer();

    private:
        int choice;
        std::vector<std::string> players;
};

#endif // MENU_H