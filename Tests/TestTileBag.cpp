#include "../LinkedList.h"
#include "../Tile.h"
#include "../TileBag.h"

#include <iostream>
#include <string>

int main(void){
    
    LinkedList* list = new LinkedList();
    TileBag* tb = new TileBag(list);

    Tile* tl1 = new Tile('A', 1);
    Tile* tl2 = new Tile('B', 1);
    Tile* tl3 = new Tile('C', 1);

    tb->addBack(tl1);
    tb->addBack(tl2);
    tb->addBack(tl3);
    std::cout << tb->getSize() << std::endl;

    for (int i = 0; i < tb->getSize(); i++){
        std::cout << tb->getTile(i)->getLetter();
        std::cout << ", ";
        std::cout << tb->getTile(i)->getValue();
        std::cout << std::endl;
    }

    std::cout << std::endl;

    tb->removeFront();
    std::cout << tb->getSize() << std::endl;
    for (int i = 0; i < tb->getSize(); i++){
        std::cout << tb->getTile(i)->getLetter();
        std::cout << ", ";
        std::cout << tb->getTile(i)->getValue();
        std::cout << std::endl;
    }

    return 0;
}