#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "Tile.h"
#include "LinkedList.h"
#include "TileBag.h"

#include <vector>

#define PLAYER_HAND_AMOUNT     7

class Player{
    public:
        Player();
        Player(std::string name);

        int getScore();
        void setScore(int Score);

        std::string getName();
        void setName(std::string name);
        void assignHand(std::vector<Tile*> player_hand, TileBag* tb);
        std::vector<Tile*> getHand();
        void printHand();
        bool isTileInHand(Tile* tile);

    private:
        std::vector<Tile*> _player_hand;
        std::string name;
        int score;
};

#endif // ASSIGN2_PLAYER_H