#include "../GameEngine.h"

int main(void){
    Player* pl = new Player();
    pl->setName("testN");
    std::vector<Player*> players;
    players.push_back(pl);

    LinkedList* list = new LinkedList();
    TileBag* tb = new TileBag(list);
    GameBoard* gb = new GameBoard();

    GameEngine* ge = new GameEngine(tb, players, gb);

    // pl->setHand(tb);
    // ge->valueByLetter('A');
    // std::cout << pl->getHandSize() << std::endl;

    // bool test = false;
    // while (test == false){
    //     test = true;
    //     std::cout << "blah" << std::endl;
    // }
    std::string input = "place c at c1";
    std::cout << ge->argTokenizer(input).size();

}

