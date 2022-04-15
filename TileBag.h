#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include "LinkedList.h"
#include "Tile.h"

#define TILE_MAX    98

class TileBag{
    public:
        TileBag();
        TileBag(LinkedList* tile_list);
        ~TileBag();
        
        Tile* getFront();
        Tile* getTile(int i);

        void addBack(Tile* tile);
        void setAsList(LinkedList* tile_list);
        LinkedList* getList();
        
        void remove(int i);
        void removeFront();
        void removeBack();
        int getSize();

    private:
        LinkedList* tile_list;
        void shuffle();
};

#endif // ASSIGN2_TILEBAG_H