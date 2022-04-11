#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

class Menu {
    public:
        Menu();
        ~Menu();

        void runMenu();
        void printMenu();
        void runChoice();
        
    private:
        int choice;
};

#endif // MENU_H