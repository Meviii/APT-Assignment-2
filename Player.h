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
        Player(std::string name, LinkedList* hand);

        int getScore();
        void setScore(int Score);

        std::string getName();
        void setName(std::string name);
        LinkedList* getHand();
        void setHand(TileBag* tb);
        void printHand();
        bool isTileInHand(Letter letter);
        Tile* getTileInHand(Letter letter);
        void removeTileInHand(Letter letter);

        bool canDrawTile(TileBag* tb);
        void drawTile(TileBag* tb);

    private:
        std::string name;
        int score;
        LinkedList* hand;
};

#endif // ASSIGN2_PLAYER_H