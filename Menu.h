#ifndef MENU_H
#define MENU_H

#include "Player.h"
#include "GameBoard.h"
#include "LinkedList.h"
#include "Tile.h"
#include "TileBag.h"
#include "Node.h"
#include "GameEngine.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <ctype.h>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;
using std::vector;
using std::ws;

class Menu
{
public:
    Menu();
    ~Menu();

    void runMenu();
    void printMenu();
    void runChoice();
    void printCredits();
    void playerSelection(int i);
    void playerCheck();
    void newGame();
    vector<string> argTokenizer(string input);
    int argCounter(string input);
    bool isTwoPlayer();
    void loadGame(string inputFile);

private:
    int choice;
    vector<Player *> players;
};

#endif // MENU_H