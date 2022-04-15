#include "../LinkedList.h"
#include "../Tile.h"
#include "../TileBag.h"

#include <iostream>
#include <random>
#include <fstream>

void printList(TileBag* tb);

int main(void){
    
    LinkedList* list = new LinkedList();
    TileBag* tb = new TileBag(list);

    Tile* tl1 = new Tile('A', 1);
    Tile* tl2 = new Tile('B', 1);
    Tile* tl3 = new Tile('C', 1);

    tb->addBack(tl1);
    tb->addBack(tl2);
    tb->addBack(tl3);

    //printList(tb);

    return 0;
}

void printList(TileBag* tb){
    for (int i = 0; i < tb->getSize(); i++){
        std::cout << tb->getTile(i)->getLetter();
        std::cout << ", ";
        std::cout << tb->getTile(i)->getValue();
        std::cout << std::endl;
    }
}
