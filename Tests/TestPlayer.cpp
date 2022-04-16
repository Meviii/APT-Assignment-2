#include "../LinkedList.h"
#include "../Tile.h"
#include "../Player.h"

#include <iostream>
#include <string>

int main(void){
    Player* pl = new Player();
    std::vector<Tile*> hand;
    LinkedList* list = new LinkedList();
    TileBag* tb = new TileBag(list);

    pl->setName("test");
    pl->assignHand(hand, tb);
    pl->printHand();

    Tile* testTileInHand = pl->getHand()[0];
    std::cout << pl->isTileInHand(testTileInHand) << std::endl;
}
