#include "../GameEngine.h"

    void testGamePlay();
    int testValueByLetter(Letter letter);
    vector<string> testArgTokenizer(string input);
    void testPlaceTile(string input);
    void testChangePlayer();
    void testReplaceTile(string input);
    bool testCheckGameOver();
    void testPrintWinner();
    void testSaveGame(string inputFile);

class TestGameEngine
{
    private:

    bool isGameOver;
    TileBag *tb;
    vector<Player *> players;
    GameBoard *gb;
    int curr_player_turn;
    Player *curr_player;
    map<Letter, int> letterValue = {{'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4}, {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8}, {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4}, {'Z', 10}};


    public:

    TestGameEngine()
    {
    }

    TestGameEngine(TileBag *tb, std::vector<Player *> players, GameBoard *gb)
    {
        this->tb = tb;
        this->players = players;
        this->gb = gb;
    }


    void testGamePlay()
    {

        for (Player *p : players)
        {
            p->setHand(tb);
        }

        this->curr_player_turn = 0;
        curr_player = players[curr_player_turn];

        isGameOver = false;

        while (isGameOver == false)
        {
            gb->printBoard();
            if (isGameOver == false)
            {
                if (this->testCheckGameOver() == true)
                {
                    this->testPrintWinner();
                }

                string input;
                cout << endl;
                cout << curr_player->getName() << ", it's your turn" << endl;
                cout << endl;
                for (Player *p : players)
                {
                    cout << "Score for " << p->getName() << ": " << p->getScore() << endl;
                }
                cout << endl;
                curr_player->printHand();

                bool turn_end = false;
                int tile_place_counter = 0;
                while (turn_end == false)
                {
                    cout << "> ";
                    while (!getline(cin >> ws, input))
                    {
                        cout << "Incorrect input" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    transform(input.begin(), input.end(), input.begin(), ::toupper);

                    if (input == "PLACE DONE")
                    {
                        if (curr_player->getPassCounter() == 1)
                        {
                            curr_player->setPassCounter(0);
                        }
                        testChangePlayer();
                        turn_end = true;
                    }
                    else if (input == "PASS")
                    {
                        curr_player->setPassCounter((curr_player->getPassCounter() + 1));
                        testChangePlayer();
                        turn_end = true;
                    }
                    else if (this->testArgTokenizer(input).size() == 4)
                    {
                        if (input.substr(0, 6) == "PLACE " && input.substr(6, 1).size() == 1 && input.substr(8, 3) == "AT " && input.substr(11, 2).size() <= 3)
                        {
                            tile_place_counter += 1;
                            if (tile_place_counter == 7)
                            {
                                cout << "BINGOD!!!" << endl;
                                cout << "You have scored an additional 50 points" << endl;
                                curr_player->setScore(curr_player->getScore() + 50);
                            }
                            testPlaceTile(input);
                            curr_player->printHand();
                        }
                    }
                    else if (this->testArgTokenizer(input).size() == 2)
                    {
                        if (input.substr(0, 8) == "REPLACE " && input.substr(6, 1).size() == 1)
                        {

                            testReplaceTile(input);
                            turn_end = true;
                        }
                    }
                    else if (input == "QUIT")
                    {
                        isGameOver = true;
                        std::cout << "Goodbye!" << std::endl;
                        std::abort();
                    }
                    else if (input == "SAVE")
                    {
                        std::string save_file;
                        std::cout << "Please enter a filename to save: " << std::endl;
                        std::cout << "> ";
                        while (!(std::cin >> save_file))
                        {
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            std::cout << "Invalid input" << std::endl;
                        }
                        this->testSaveGame(save_file);
                        std::cout << "Continuing game..." << std::endl;
                    }
                    else
                    {
                        std::cout << "Incorrect Input" << std::endl;
                    }
                }
            }
        }
    }

    int testValueByLetter(Letter letter)
    {
        return letterValue.find(letter)->second;
    }

    vector<string> testArgTokenizer(string input)
    {
        stringstream ss(input);
        vector<string> s;

        while (ss >> input)
        {
            s.push_back(input);
        }
        return s;
    }

    void testPlaceTile(std::string input)
    {
        std::string arg;
        std::string tileHandLetter;
        std::string holder;
        std::string positionOnBoard;
        int valueOfPositionOnBoard;

        std::vector<std::string> s = this->testArgTokenizer(input);

        arg = s[0];
        tileHandLetter = s[1];
        holder = s[2];
        positionOnBoard = s[3];
        valueOfPositionOnBoard = std::stoi(positionOnBoard.substr(1, 3));

        transform(tileHandLetter.begin(), tileHandLetter.end(), tileHandLetter.begin(), ::toupper);
        transform(positionOnBoard.begin(), positionOnBoard.end(), positionOnBoard.begin(), ::toupper);

        char charHandLetter = tileHandLetter[0];
        Tile *tile_to_place = new Tile((Letter)charHandLetter, (Value)this->testValueByLetter(((Letter)charHandLetter)));

        if (gb->isTileValid(gb->boardRow.find(positionOnBoard[0])->second, valueOfPositionOnBoard) && curr_player->isTileInHand(charHandLetter))
        {

            gb->addTile(gb->boardRow.find(positionOnBoard[0])->second, valueOfPositionOnBoard, tile_to_place);
            curr_player->removeTileInHand(charHandLetter);

            if (curr_player->canDrawTile(tb))
            {
                curr_player->drawTile(tb);
            }

            cout << "Added tile to " << positionOnBoard[0] << valueOfPositionOnBoard << endl;
            curr_player->setScore(curr_player->getScore() + (Value)this->testValueByLetter(((Letter)charHandLetter)));
            gb->printBoard();
        }
        else
        {
            cout << "You cannot place that tile" << endl;
            cout << endl;
        }
    }

    void testChangePlayer()
    {
        int players_size = players.size();

        if (players_size > (curr_player_turn + 1))
        {
            curr_player_turn += 1;
            curr_player = players[curr_player_turn];
        }
        else if (players_size == (curr_player_turn + 1))
        {
            curr_player_turn = 0;
            curr_player = players[curr_player_turn];
        }
        else
        {
            cout << "Error while switching player turn" << endl;
        }
    }

    void testReplaceTile(std::string input)
    {
        char tileLetterToRemove;

        vector<string> s = this->testArgTokenizer(input);
        tileLetterToRemove = s[1][0];

        if (curr_player->isTileInHand(tileLetterToRemove))
        {
            curr_player->removeTileInHand(tileLetterToRemove);

            if (curr_player->canDrawTile(tb))
            {
                curr_player->drawTile(tb);
            }
            cout << "Tile removed from hand" << endl;
            this->testChangePlayer();
        }
        else
        {
            cout << "You do not own that tile." << endl;
        }
    }

    bool testCheckGameOver()
    {
        if (tb->getSize() == 0)
        {
            this->isGameOver = true;
            return true;
        }

        for (Player *p : players)
        {
            if (p->getHandSize() == 0 || p->getPassCounter() == 2)
            {
                this->isGameOver = true;
                return true;
            }
        }

        return false;
    }

    void testPrintWinner()
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Game Over!" << std::endl;
        
        Player* tmp = new Player();
        int highest_score = 0;
        for (Player *p : players)
        {
            if (p->getScore() > highest_score)
            {
                tmp->setName(p->getName());
                tmp->setScore(p->getScore());
                highest_score = p->getScore();
            }
            cout << "Score for " << p->getName() << ": " << p->getScore() << endl;
        }
        cout << "Player " << tmp->getName() << " won!" << endl;
        cout << endl;
        cout << "Goodbye!" << endl;
        return;
    }

    void testSaveGame(std::string inputFile)
    {
        std::ofstream gameData;

        gameData.open(inputFile);

        if (!gameData)
        {
            std::cout << "Error saving game" << std::endl;
        }
        else
        {
            gameData << players.size() << "\n";

            for(Player* p : players){
                gameData << p->getName() << "\n";
                gameData << p->getScore() << "\n";
                gameData << p->getPassCounter() << "\n";

                LinkedList *player_hand = p->getHand();
                Node *h = player_hand->getHead();
                for (int i = 0; i < PLAYER_HAND_AMOUNT; i++)
                {
                    if (i == (PLAYER_HAND_AMOUNT - 1))
                    {
                        gameData << h->tile->getLetter() << "-" << h->tile->getValue() << "\n";
                    }
                    else
                    {
                        gameData << h->tile->getLetter() << "-" << h->tile->getValue() << ", ";
                    }
                    h = h->next;
                }
            }
            int tb_size = tb->getSize();
            LinkedList *tb_list = tb->getList();
            Node *tb_h = tb_list->getHead();
            for (int i = 0; i < tb_size; i++)
            {
                if (i == (tb_size - 1))
                {
                    gameData << tb_h->tile->getLetter() << "-" << tb_h->tile->getValue() << "\n";
                }
                else
                {
                    gameData << tb_h->tile->getLetter() << "-" << tb_h->tile->getValue() << ", ";
                }
                tb_h = tb_h->next;
            }
            char alpha[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};

            gameData << "    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  "
                    << "\n";
            gameData << "---------------------------------------------------------------"
                    << "\n";
            std::vector<std::vector<Tile *>> board = gb->getBoard();
            std::map<Tile *, std::string> tl_on_board;
            int gb_size = gb->getSize();
            for (int row = 0; row < gb_size; row++)
            {
                gameData << alpha[row] << " ";
                for (int col = 0; col < gb_size; col++)
                {
                    if (board[row][col] == nullptr)
                    {
                        gameData << "| ";
                    }
                    else if (board[row][col] != nullptr && board[row][col]->getLetter() == ' ')
                    {
                        gameData << "| " << board[row][col]->getLetter() << " ";
                    }
                    else
                    {
                        string tmp = to_string(col);
                        tl_on_board.insert({board[row][col], (alpha[row] + tmp)});
                        gameData << "| " << board[row][col]->getLetter() << " ";
                    }
                }
                gameData << "|"
                        << "\n";
            }
            unsigned int iter_sz = 0;
            for (auto const &x : tl_on_board)
            {
                if (iter_sz == tl_on_board.size() - 1)
                {
                    gameData << x.first->getLetter() << "@" << x.second;
                }
                else
                {
                    gameData << x.first->getLetter() << "@" << x.second << ", ";
                }
                iter_sz += 1;
            }
        }
        gameData.close();
    }
};


int main(void){
    Player* pl1 = new Player();
    Player* pl2 = new Player();
    LinkedList* list = new LinkedList();
    TileBag* tb = new TileBag(list);
    GameBoard* gb = new GameBoard();

    pl1->setName("test1");
    pl1->setScore(50);
    pl1->setPassCounter(0);
    pl1->setHand(tb);

    pl1->setName("test2");
    pl1->setScore(60);
    pl1->setPassCounter(0);
    pl1->setHand(tb);

    std::vector<Player*> players;
    players.push_back(pl1);
    players.push_back(pl2);

    TestGameEngine* ge = new TestGameEngine(tb, players, gb);

    pl1->setHand(tb);
    ge->testValueByLetter('X');


    //Test 1: Return values of tiles by their letter
    for(int i = 0; i < 26; i++){
        char currLetter = ('A' + i);
        std::cout << currLetter << " has a value of: " << ge->testValueByLetter('A' + i) << std::endl;
    }


    //Test 2: Replace a player's Tile with another from the TileBag
    
    Tile* B = new Tile('B', 3);
    pl2->addToHand(B);
    //ge->testReplaceTile("B");
    pl2->printHand();

    //Test 3: Check game over conditions
    //ge->testCheckGameOver





    //Test 4: Player with highest points is the winner

    //ge->testPrintWinner();


}

