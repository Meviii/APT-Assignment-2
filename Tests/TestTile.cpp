#include "../Tile.h"

#include <iostream>
#include <string>

int main(void){
    Tile* tl1 = new Tile('A',1);

    std::cout << "Letter: " << tl1->getLetter() << std::endl;
    std::cout << "Value: " << tl1->getValue() << std::endl;
    std::cout << "Value by letter ('Q'): " << tl1->valueByLetter('Q');
}
