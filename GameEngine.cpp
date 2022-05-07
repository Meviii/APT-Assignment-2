#include "GameEngine.h"

GameEngine::GameEngine(){
    
}
/*
 * Construct a new GameEngine:: GameEngine object
 * Assigns TileBag, Players and GameBoard
 */
GameEngine::GameEngine(TileBag* tb, std::vector<Player*> players, GameBoard* gb) {
    this->tb = tb;
    this->players = players;
    this->gb = gb;
}

// Implementation of the Scrabble game
void GameEngine::gamePlay(){

    for (Player* p : players){
        p->setHand(tb);
    }

    this->curr_player_turn = 0;
    curr_player = players[curr_player_turn];

    isGameOver = false;

    while (isGameOver == false){
        gb->printBoard();
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
                std::transform(input.begin(), input.end(), input.begin(), ::toupper);

                // CHOICE #1: Current player has finished placing Tiles
                if (input == "PLACE DONE"){
                    if (curr_player->getPassCounter() == 1){
                        curr_player->setPassCounter(0);
                    }
                    changePlayer();
                    turn_end = true;

                // CHOICE #2: Current player passing their turn
                }else if (input == "PASS"){
                    curr_player->setPassCounter((curr_player->getPassCounter() + 1));
                    changePlayer();
                    turn_end = true;

                // CHOICE #3: Current player placing tiles
                }else if(this->argTokenizer(input).size() == 4){
                    if (input.substr(0,6) == "PLACE " && input.substr(6,1).size() == 1 && input.substr(8,3) == "AT " && input.substr(11,2).size() <= 3){ // Main Block #3

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
                // CHOICE #4: Replaces current players missing Tiles from the TileBag
                }else if (this->argTokenizer(input).size() == 2){
                    if (input.substr(0,8) == "REPLACE " && input.substr(6,1).size() == 1){ 

                    replaceTile(input);
                    turn_end = true;
                    }
                // CHOICE #5: Quit the game
                }else if (input == "QUIT"){
                    isGameOver = true;
                    std::cout << "Goodbye!" << std::endl;
                    std::abort();
                // CHOICE #6: Save state of game in the specified save_file
                }else if (input == "SAVE"){
                    std::string save_file;
                    std::cout << "Please enter a filename to save: " << std::endl;
                    std::cout << "> ";
                    while(!(std::cin >> save_file)){
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Invalid input" << std::endl;
                    }
                    this->saveGame(save_file);
                    std::cout << "Continuing game..." << std::endl;
                }else{ 
                    // INVALID INPUT: Current player to re-enter their choice
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
/*
 * 
 * arg holds argument : place
 * tileHandLetter holds tile letter for player hand
 * holder holds : at
 * positionOnBoard holds position to place on board
 * valueOfPositionOnBoard holds the point value of the position. eg. holds the '1' value of 'C1'
 */
void GameEngine::placeTile(std::string input){
    std::string arg;
    std::string tileHandLetter;
    std::string holder;
    std::string positionOnBoard;
    int valueOfPositionOnBoard;

    std::vector<std::string> s = this->argTokenizer(input);
    
    arg = s[0];
    tileHandLetter = s[1];
    holder = s[2];
    positionOnBoard = s[3];
    valueOfPositionOnBoard = std::stoi(positionOnBoard.substr(1,3));

    std::transform(tileHandLetter.begin(), tileHandLetter.end(), tileHandLetter.begin(), ::toupper);
    std::transform(positionOnBoard.begin(), positionOnBoard.end(), positionOnBoard.begin(), ::toupper);

    char charHandLetter = tileHandLetter[0];
    Tile* tile_to_place = new Tile((Letter) charHandLetter,(Value) this->valueByLetter( ((Letter) charHandLetter)));
    
    if (gb->isTileValid(gb->boardRow.find(positionOnBoard[0])->second, valueOfPositionOnBoard) && curr_player->isTileInHand(charHandLetter)) {
        
        //Place Tile
        gb->addTile(gb->boardRow.find(positionOnBoard[0])->second, valueOfPositionOnBoard, tile_to_place); // place tile
        //Remove Tile
        curr_player->removeTileInHand(charHandLetter);

        //Draw Tile if available
        if (curr_player->canDrawTile(tb)){
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

void GameEngine::saveGame(std::string inputFile){
    std::ofstream gameData;

    gameData.open(inputFile);

    if (!gameData){
        std::cout << "Error saving game" << std::endl;
    }else{
        // Save player amount
        gameData << players.size() << "\n";

        // Save players
        for(Player* p : players){
            gameData << p->getName() << "\n";
            gameData << p->getScore() << "\n";
            gameData << p->getPassCounter() << "\n";

            LinkedList* player_hand = p->getHand();
            Node* h = player_hand->getHead();
            for (int i = 0; i < PLAYER_HAND_AMOUNT; i++){
                if (i == (PLAYER_HAND_AMOUNT-1)){
                    gameData << h->tile->getLetter() << "-" << h->tile->getValue() << "\n";
                }else{
                    gameData << h->tile->getLetter() << "-" << h->tile->getValue() << ", ";
                }
                h = h->next;
            }
        }
        // Save TileBag
        int tb_size = tb->getSize();
        LinkedList* tb_list = tb->getList();
        Node* tb_h = tb_list->getHead();
        for (int i = 0; i < tb_size; i++){ 
            if (i == (tb_size-1)){
                gameData << tb_h->tile->getLetter() << "-" << tb_h->tile->getValue() << "\n";
            }else{
                gameData << tb_h->tile->getLetter() << "-" << tb_h->tile->getValue() << ", ";
            }
            tb_h = tb_h->next;
        }
        // Save GameBoard's current state
        char alpha[15] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
    
        gameData << "    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  " << "\n";
        gameData << "---------------------------------------------------------------" << "\n";
        std::vector<std::vector<Tile *>> board = gb->getBoard();
        std::map<Tile*, std::string> tl_on_board;
        int gb_size = gb->getSize();
        for (int row = 0; row < gb_size; row++){
            gameData << alpha[row] << " ";
            for (int col = 0; col < gb_size; col++){
                if (board[row][col] == nullptr){
                    gameData << "| ";
                }else if (board[row][col] != nullptr && board[row][col]->getLetter() == ' '){
                    gameData << "| " << board[row][col]->getLetter() << " ";
                }else{
                    std::string tmp = std::to_string(col);
                    tl_on_board.insert({board[row][col], (alpha[row] + tmp)});
                    gameData << "| " << board[row][col]->getLetter() << " ";
                }
            }
            gameData << "|" << "\n";
        }
        // Save Tiles
        unsigned int iter_sz = 0;
        for (auto const& x : tl_on_board){
            if (iter_sz == tl_on_board.size()-1){
                gameData << x.first->getLetter() << "@" << x.second;
            }else{
                gameData << x.first->getLetter() << "@" << x.second << ", ";
            }
            iter_sz += 1;
        }
    }
    gameData.close();
}

