#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Player.h"
#include "GameBoard.h"
#include "LinkedList.h"
#include "Tile.h"
#include "TileBag.h"
#include "Node.h"

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

class GameEngine {
    public:
        GameEngine();
        GameEngine(TileBag* tb, std::vector<Player*> players, GameBoard* gb);
        void gamePlay();
        int valueByLetter(Letter letter);
        std::vector<std::string> argTokenizer(std::string input);
        int argCounter(std::string input);
        void placeTile(std::string input);
        void changePlayer();
        void replaceTile(std::string input);
        void checkGameOver();

    private:
        TileBag* tb;
        std::vector<Player*> players;
        GameBoard* gb;
        int curr_player_turn;
        Player* curr_player;
        std::map<Letter, int> letterValue = {{'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4}, {'G', 2},
                                        {'H', 4}, {'I', 1}, {'J', 8}, {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1},
                                        {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1},
                                        {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4}, {'Z', 10}};

};

#endif // MENU_H