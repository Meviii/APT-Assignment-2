#include "../LinkedList.h"
#include "../Tile.h"

#include <iostream>
#include <string>

int main(void){

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
    ll->addFront(tl3);
    ll->printList();
    std::cout << std::endl;
    ll->removeNode(0);
    ll->printList();


}

