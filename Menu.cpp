#include <iostream>
#include <string>
#include <vector>

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

    while (this->choice <= 4 && std::cin.eof() != true) {
        this->printMenu();
        std::cout << "> ";
        std::cin >> this->choice;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        this->runChoice();
    }
    // else if (std::cin.eof()) {
    //     std::cout << "Goodbye" << std::endl;
    //     return;
    // }
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
        this->playerCheck();
    }else if(this->choice == 2) {
        std::cout << "Option 2 chosen" << std::endl;

    }else if(this->choice == 3) {
        this->printCredits();

    }else if(this->choice == 4){
        std::cout << "Goodbye!" << std::endl;
        this->choice = 4;

    }else if(std::cin.eof() == true) {
        std::cout << "Goodbye!" << std::endl;
    }else {
        this->choice = 0;
        std::cout << "Invalid Input" << std::endl;
    }
}

void Menu::printCredits(){
    std::cout << "Name: Mevlut Saluk" << std::endl;
    std::cout << "Student ID: S3717696" << std::endl;
    std::cout << "Email: S3717696@rmit.edu.com.au" << std::endl;
    std::cout << std::endl;
}


void Menu::playerCheck(){
    int player_count;

    Player* player_1 = new Player();
    Player* player_2 = new Player();
    std::cout << std::endl<< "Starting a New Game" << std::endl;
    std::cout << "Player count? 2-4" << std::endl;
    std::cout << "> ";
    std::cin >> player_count;
    if (player_count >= 2 && player_count <= 4){
        if (player_count == 2 && this->isTwoPlayer() == true){
            this->playerSelection(player_count);
        }else if (player_count > 2 && this->isTwoPlayer() == true){
            std::cout << "Currently support 2-player only." << std::endl;
            this->runChoice();
        }
    }else{
        this->choice = 1;
        this->runMenu();
    }

    player_1->setName(players[0]);
    player_2->setName(players[1]);

    std::cout << "Let's Play!" << std::endl;
}

void Menu::playerSelection(int i){
    std::string player_name;

    for (int x = 1; x < i+1; x++){
        if (x == i+5){
            std::cout << "Reached max player limit of 4" << std::endl;
            return;
        }
        std::cout << "Enter a name for player " << x << " (uppercase characters only): " << std::endl;
        std::cout << "> ";
        std::cin >> player_name;
        players.push_back(player_name);
        std::cout << "Player" << x << " name set to: " << player_name << std::endl;
        std::cin.clear();
    }
}

bool Menu::isTwoPlayer(){
    return true;
}
// std::string player_name;
//     Player* players = new Player[i];
//     std::vector<Player*> players;

//     for (int x = 1; x <= i+1; x++){
//         if (x == i+5){
//             std::cout << "Reached max player limit of 4" << std::endl;
//             return;
//         }
//         std::cout << "Enter a name for player " << x << " (uppercase characters only): " << std::endl;
//         std::cout << "> ";
//         std::cin >> player_name;
//         players[x].setName(player_name);
//         std::cin.clear();
//         std::cout << "Player name set to: " << players[x].getName() << std::endl;
//     }
//     return;