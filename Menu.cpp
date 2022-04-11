#include <iostream>
#include <string>

#include "Menu.h"

Menu::Menu() {
    std::cout << std::endl;
    std::cout << "Welcome to Scrabble!" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << std::endl;
}

Menu::~Menu(){}

void Menu::runMenu(){
    this->choice = 0;

    if (this->choice <= 4 && std::cin.eof() != true) {
        this->printMenu();
        std::cout << "> ";
        std::cin >> this->choice;
        std::cin.clear();
        this->runChoice();
    }
}

void Menu::printMenu(){

    std::cout << "Menu" << std::endl;
    std::cout << "----\n" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits (Show student information)" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << std::endl;
}

void Menu::runChoice(){
    if(this->choice == 1) {
        std::cout << std::endl<< "Starting a New Game" << std::endl;
    }else if(this->choice == 2) {

    }else if(this->choice == 3) {

    }else if(this->choice == 4){
        std::cout << "Goodbye!" << std::endl;
        this->choice = 4;
    }else if(std::cin.eof()) {
        
    }else {
        this->choice = 0;
        std::cout << "Invalid Input" << std::endl;
    }
}