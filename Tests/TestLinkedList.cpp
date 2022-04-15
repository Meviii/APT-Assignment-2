#include "../LinkedList.h"
#include "../Tile.h"

#include <iostream>
#include <string>

int main(void){
    int size;

    LinkedList* ll = new LinkedList;
    Tile* tl1 = new Tile('A',1);
    Tile* tl2 = new Tile('B',1);
    Tile* tl3 = new Tile('Q',10);
    
    std::cout << "Added 3 Nodes: " << std::endl;
    std::cout << "Letter: " << tl1->getLetter() << ", Value: " << tl1->getValue() << std::endl;
    std::cout << "Letter: " << tl2->getLetter() << ", Value: " << tl2->getValue() << std::endl;
    std::cout << "Letter: " << tl3->getLetter() << ", Value: " << tl3->getValue() << std::endl;
    std::cout << std::endl;

    ll->addBack(tl2);
    ll->addFront(tl1);
    ll->addBack(tl3);
    ll->printList();
    Tile* tl4 = new Tile(ll->getNodeAsTile(1)->getLetter(), ll->getNodeAsTile(1)->getValue());
    ll->addFront(tl4);
    std::cout << std::endl;
    ll->printList();
    std::cout << std::endl;
    std::cout << ll->getHead()->tile->getLetter() << ", " << ll->getHead()->tile->getValue() << std::endl;
    size = ll->getSize()-1;
    std::cout << ll->getNode(size)->tile->getLetter() << ", " << ll->getNode(size)->tile->getValue() << std::endl;
    std::cout << "Is empty? " << ll->checkEmpty() << std::endl;
}

