#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "Tile.h"
#include "LinkedList.h"

#include <String>

class Player{
    public:
        Player();
        Player(std::string name);

        int getScore();
        void setScore(int Score);

        std::string getName();
        void setName(std::string name);

    private:
        std::string name;
        int score;
};

#endif // ASSIGN2_PLAYER_H