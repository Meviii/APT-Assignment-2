#include "GameEngine.h"

GameEngine::GameEngine(){
    
}

GameEngine::GameEngine(TileBag* tb, std::vector<Player*> players, GameBoard* gb) {
    this->tb = tb;
    this->players = players;
    this->gb = gb;
}

void GameEngine::gamePlay(){

    for (Player* p : players){
        p->setHand(tb);
    }

    this->curr_player_turn = 0;
    curr_player = players[curr_player_turn];

    isGameOver = false;

    while (isGameOver == false){

        if (isGameOver == false){
            if (this->checkGameOver() == true){
                this->printWinner();
            }

            std::string input;
            std::cout << std::endl;
            std::cout << curr_player->getName() << ", it's your turn" << std::endl;
            std::cout << std::endl;
            for (Player* p : players){
                std::cout << "Score for " << p->getName() << ": " << p->getScore() << std::endl;
            }
            std::cout << std::endl;
            curr_player->printHand();
            
            bool turn_end = false;
            int tile_place_counter = 0;
            while (turn_end == false){
                std::cout << "> ";
                while (!std::getline(std::cin >> std::ws, input)){
                    std::cout << "Incorrect input" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
                std::cout << input << std::endl;
                if (input == "place Done"){ // Main Block #1
                    if (curr_player->getPassCounter() == 1){
                        curr_player->setPassCounter(0);
                    }
                    changePlayer();
                    turn_end = true;

                }else if (input == "skip"){ // Main Block #2
                    curr_player->setPassCounter((curr_player->getPassCounter() + 1));
                    changePlayer();
                    turn_end = true;

                }else if(this->argTokenizer(input).size() == 4){ // Main Block #3
                    if (input.substr(0,6) == "place " && input.substr(6,1).size() == 1 && input.substr(8,3) == "at " && input.substr(11,2).size() <= 3){ // Main Block #3

                        tile_place_counter += 1;
                        if (tile_place_counter == 7){
                            std::cout << "BINGOD!!!" << std::endl;
                            std::cout << "You have scored an additional 50 points" << std::endl;
                            curr_player->setScore(curr_player->getScore() + 50);
                        }
                        placeTile(input);
                        curr_player->printHand();
                    }else{
                        std::cout << "Invalid Input" << std::endl;
                    }
                }else if (this->argTokenizer(input).size() == 2){
                    if (input.substr(0,8) == "replace " && input.substr(6,1).size() == 1){ // Main Block #4

                    replaceTile(input);
                    turn_end = true;
                    }

                }else{ // Main Else Block
                    std::cout << "Incorrect Input" << std::endl;
                }
            }
        }
    }
}

int GameEngine::valueByLetter(Letter letter){
    return letterValue.find(letter)->second;
}

std::vector<std::string> GameEngine::argTokenizer(std::string input){
    std::stringstream ss(input);
    std::vector<std::string> s;

    while (ss >> input) {
        s.push_back(input);
    }
    return s;
}

void GameEngine::placeTile(std::string input){
    std::string arg;
    std::string tileHandLetter;
    std::string holder;
    std::string positionOnBoard;
    int valueOfPositionOnBoard;

    std::vector<std::string> s = this->argTokenizer(input);

    arg = s[0]; // holds argument : place
    tileHandLetter = s[1]; // holds tile letter for playser hand
    holder = s[2]; // holds : at
    positionOnBoard = s[3]; // holds position to place on board
    valueOfPositionOnBoard = std::stoi(positionOnBoard.substr(1,3)); // holds the '1' value of 'C1'

    char charHandLetter = tileHandLetter[0];
    Tile* tile_to_place = new Tile((Letter) charHandLetter,(Value) this->valueByLetter( ((Letter) charHandLetter)));
    
    if (gb->isTileValid(gb->boardRow.find(positionOnBoard[0])->second, valueOfPositionOnBoard) && curr_player->isTileInHand(charHandLetter)) {
        
        gb->addTile(gb->boardRow.find(positionOnBoard[0])->second, valueOfPositionOnBoard, tile_to_place); // place tile
        curr_player->removeTileInHand(charHandLetter); // remove the tile from hand

        if (curr_player->canDrawTile(tb)){ // draw tile if available
            curr_player->drawTile(tb);
        }

        std::cout << "Added tile to " << positionOnBoard[0] << valueOfPositionOnBoard << std::endl;
        curr_player->setScore(curr_player->getScore() + (Value) this->valueByLetter( ((Letter) charHandLetter)));
        gb->printBoard();
    }else{
        std::cout << "You cannot place that tile" << std::endl;
        std::cout << std::endl;
    }
}

void GameEngine::changePlayer(){
    int players_size = players.size();

    if (players_size > (curr_player_turn + 1)){
        curr_player_turn += 1;
        curr_player = players[curr_player_turn];
    }else if (players_size == (curr_player_turn + 1)){
        curr_player_turn = 0;
        curr_player = players[curr_player_turn];
    }else{
        std::cout << "Error while switching player turn" << std::endl;
    }
}

void GameEngine::replaceTile(std::string input){
    char tileLetterToRemove;

    std::vector<std::string> s = this->argTokenizer(input);
    tileLetterToRemove = s[1][0];

    if (curr_player->isTileInHand(tileLetterToRemove)){
        curr_player->removeTileInHand(tileLetterToRemove);

        if (curr_player->canDrawTile(tb)){
            curr_player->drawTile(tb);
        }
        std::cout << "Tile removed from hand" << std::endl;
        this->changePlayer();
    }else{
        std::cout << "You do not own that tile." << std::endl;
    }
}

bool GameEngine::checkGameOver(){

    if (tb->getSize() == 0){
        this->isGameOver = true;
        return true;
    }

    for (Player* p : players){
        if (p->getHandSize() == 0 || p->getPassCounter() == 2){
            this->isGameOver = true;
            return true;
        }
    }

    return false;
}

void GameEngine::printWinner(){
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Game Over!" << std::endl;
    
    Player* tmp = new Player();
    int highest_score = 0;
    for (Player* p : players){
        if (p->getScore() > highest_score){
            tmp->setName(p->getName());
            tmp->setScore(p->getScore());
            highest_score = p->getScore();
        }
        std::cout << "Score for " << p->getName() << ": " << p->getScore() << std::endl;
    }
    std::cout << "Player " << tmp->getName() << " won!" << std::endl;
    std::cout << std::endl;
    std::cout << "Goodbye!" << std::endl;
    return;
}

// BACKUP :D

// void GameEngine::gamePlay(){

//     for (Player* p : players){
//         p->setHand(tb);
//     }

//     this->curr_player_turn = 0;
//     curr_player = players[curr_player_turn];

//     isGameOver = false;

//     while (isGameOver == false){
        
//         if (this->checkGameOver() == true){
//             this->printWinner();
//         }

//         std::string input;
//         std::cout << std::endl;
//         std::cout << curr_player->getName() << ", it's your turn" << std::endl;
//         std::cout << std::endl;
//         for (Player* p : players){
//             std::cout << "Score for " << p->getName() << ": " << p->getScore() << std::endl;
//         }
//         std::cout << std::endl;
//         curr_player->printHand();

//         if (isGameOver == false){

//             std::cout << "> ";
//             while (!std::getline(std::cin >> std::ws, input)){
//                 std::cout << "Incorrect input" << std::endl;
//                 std::cin.clear();
//                 std::cin.ignore();
//             }
//             std::cout << input << std::endl;
//             std::cout << curr_player->getPassCounter() << std::endl;
//             if (input == "place Done"){ // Main Block #1

//                 if (curr_player->getPassCounter() == 1){
//                     curr_player->setPassCounter(0);
//                 }
//                 changePlayer();

//             }else if (input == "skip"){
                
//                 curr_player->setPassCounter((curr_player->getPassCounter() + 1));
//                 changePlayer();

//             }else if(input.substr(0,6) == "place " && input.substr(6,1).size() == 1 && input.substr(8,3) == "at " && input.substr(11,2).size() <= 3){ // Main Block #2

//                 placeTile(input);


//             }else if (input.substr(0,8) == "replace " && input.substr(6,1).size() == 1){ // Main Block #3

//                 replaceTile(input);

//             }else{
//                 std::cout << "Incorrect Input" << std::endl;
//             }
//         }
//     }
// }