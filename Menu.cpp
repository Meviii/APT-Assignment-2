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
    this->printMenu();

    while(!(std::cin >> this->choice)){
        if (this->choice == 99){
            return;
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input" << std::endl;
    }

    this->runChoice();

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

    while (this->choice != 4 || std::cin.eof() == true){
        if(this->choice == 1) {
            this->playerCheck();

        }else if(this->choice == 2) {
            std::cout << "Option 2 chosen" << std::endl;
            this->runMenu();
            
        }else if(this->choice == 3) {
            this->printCredits();
            this->runMenu();

        }else if(this->choice == 4){
            std::cout << "Goodbye!" << std::endl;
            return;
        }else if(std::cin.eof() == true) {
            std::cout << "Goodbye!" << std::endl;
            return;
        }else {
            std::cout << "Invalid Input" << std::endl;
            this->choice = 0;
            this->runMenu();
        }
    }
    std::cout << "Goodbye!" << std::endl;
}

void Menu::printCredits(){
    std::cout << std::endl;
    std::cout << "Name: Mevlut Saluk" << std::endl;
    std::cout << "Student ID: S3717696" << std::endl;
    std::cout << "Email: S3717696@rmit.edu.com.au" << std::endl;
    std::cout << std::endl;
}

void Menu::playerCheck(){
    int player_count;

    std::cout << std::endl<< "Starting a New Game" << std::endl;
    std::cout << "Player count? 2-4" << std::endl;
    std::cout << "> ";
    std::cin >> player_count;

    if (player_count >= 1 && player_count <= 4){
        if (player_count == 2 && this->isTwoPlayer() == true){
            this->playerSelection(player_count);
            return this->newGame();
        }else if (player_count > 2 && this->isTwoPlayer() == true){
            std::cout << "Currently support 2-player only." << std::endl;
            this->runChoice();
        }else if (player_count < 2){
            std::cout << "Single player not supported." << std::endl;
            this->runChoice();
        }
    }else{
        this->choice = 1;
        this->runMenu();
    }
}

void Menu::playerSelection(int i){
    std::string player_name;

    for (int x = 1; x < i+1; x++){
        if (x == i+5){
            std::cout << "Reached max player limit of 4" << std::endl;
            return;
        }
        std::cout << "Enter a name for player " << x << ": " << std::endl;
        std::cout << "> ";
        std::cin >> player_name;

        while(std::cin.fail() || player_name.find_first_of("0123456789") != std::string::npos){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter a valid name." << std::endl;
            std::cin >> player_name;
        }
        Player* tmp_p = new Player();
        tmp_p->setName(player_name);
        tmp_p->setScore(0);
        tmp_p->setPassCounter(0);
        players.push_back(tmp_p);
        std::cout << "Player" << x << " name set to: " << player_name << std::endl;
        std::cin.clear();
    }
    std::cout << std::endl;
}

bool Menu::isTwoPlayer(){
    return true;
}

void Menu::newGame(){
    // Player initializing
    std::cout << "Let's Play!" << std::endl;
    std::cout << std::endl;

    LinkedList* list = new LinkedList();
    TileBag* tb = new TileBag(list);
    GameBoard* gb = new GameBoard();
    
    std::cout << "Player 1 starts first." << std::endl;
    std::cout << std::endl;
    GameEngine* ge = new GameEngine(tb, players, gb);
    ge->gamePlay();
}