#include "../GameEngine.h"

int main(void){
    Player* pl = new Player();
    LinkedList* list = new LinkedList();
    TileBag* tb = new TileBag(list);
    GameBoard* gb = new GameBoard();

    pl->setName("testN");
    pl->setScore(0);
    pl->setPassCounter(0);
    pl->setHand(tb);
    std::vector<Player*> players;
    players.push_back(pl);

    GameEngine* ge = new GameEngine(tb, players, gb);

    pl->setHand(tb);
    ge->valueByLetter('A');
    std::cout << pl->getHandSize() << std::endl;

    bool test = false;
    while (test == false){
        test = true;
        std::cout << "blah" << std::endl;
    }
    // std::string tileHandLetter = "a";
    // std::string positionOnBoard = "c1";
    // std::transform(tileHandLetter.begin(), tileHandLetter.end(), tileHandLetter.begin(), ::toupper);
    // std::transform(positionOnBoard.begin(), positionOnBoard.end(), positionOnBoard.begin(), ::toupper);

    // std::cout << tileHandLetter << std::endl;
    // std::cout << positionOnBoard << std::endl;
}

