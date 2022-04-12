#include "../Tile.h"
#include "../Node.h"

#include <iostream>
#include <string>

int main(void){
    Tile* tl1 = new Tile('A',1);

    Node* tl1_node = new Node(tl1, nullptr);

    std::cout << tl1_node->tile->getLetter() << std::endl;
    std::cout << tl1_node->tile->getValue() << std::endl;
}
