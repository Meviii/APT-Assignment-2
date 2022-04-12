#include "../Tile.h"

#include <iostream>
#include <string>

int main(void){
    Tile* tl1 = new Tile('A',1);

    std::cout << tl1->getLetter() << std::endl;
    std::cout << tl1->getValue() << std::endl;
}
