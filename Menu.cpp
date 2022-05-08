#include "Menu.h"

Menu::Menu()
{
    cout << endl;
    cout << "Welcome to Scrabble!" << endl;
    cout << "--------------------" << endl;
    cout << endl;
}

Menu::~Menu() {}

void Menu::runMenu()
{
    this->choice = 0;
    this->printMenu();

    while (!(cin >> this->choice))
    {
        if (this->choice == 99)
        {
            return;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input" << endl;
    }

    this->runChoice();
}

void Menu::printMenu()
{

    cout << "Menu" << endl;
    cout << "----\n"
         << endl;
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Credits (Show student information)" << endl;
    cout << "4. Quit" << endl;
    cout << endl;
}

void Menu::runChoice()
{

    while (this->choice != 4 || cin.eof() == true)
    {
        if (this->choice == 1)
        {
            this->playerCheck();
        }
        else if (this->choice == 2)
        {
            string load_file;

            cout << "Please enter a filename to load: " << endl;
            cout << "> ";
            while (!(cin >> load_file))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input" << endl;
            }
            this->loadGame(load_file);
        }
        else if (this->choice == 3)
        {
            this->printCredits();
            this->runMenu();
        }
        else if (this->choice == 4)
        {
            cout << "Goodbye!" << endl;
            return;
        }
        else if (cin.eof() == true)
        {
            cout << "Goodbye!" << endl;
            return;
        }
        else
        {
            cout << "Invalid Input" << endl;
            this->choice = 0;
            this->runMenu();
        }
    }
    cout << "Goodbye!" << endl;
}

void Menu::printCredits()
{
    cout << endl;
    cout << "Name: Mevlut Saluk" << endl;
    cout << "Student ID: S3717696" << endl;
    cout << "Email: S3717696@rmit.edu.com.au" << endl;

    cout << endl;
    cout << "Name: Yong Hui Cheah" << endl;
    cout << "Student ID: S3778714" << endl;
    cout << "Email: S3778714@rmit.edu.com.au" << endl;

    cout << endl;
    cout << "Name: Terrence Taylor" << endl;
    cout << "Student ID: S3909238" << endl;
    cout << "Email: S3909238@student.rmit.edu.au" << endl;

    cout << endl;
    cout << "Name: Paul Lubig" << endl;
    cout << "Student ID: S3329840" << endl;
    cout << "Email: S3329840@rmit.edu.com.au" << endl;
    cout << endl;
}

void Menu::playerCheck()
{
    int player_count;

    cout << endl
         << "Starting a New Game" << endl;
    cout << "Player count? 2-4" << endl;
    cout << "> ";
    cin >> player_count;

    if (player_count >= 1 && player_count <= 4)
    {
        if (player_count == 2 && this->isTwoPlayer() == true)
        {
            this->playerSelection(player_count);
            return this->newGame();
        }
        else if (player_count > 2 && this->isTwoPlayer() == true)
        {
            cout << "Currently support 2-player only." << endl;
            this->runChoice();
        }
        else if (player_count < 2)
        {
            cout << "Single player not supported." << endl;
            this->runChoice();
        }
    }
    else
    {
        this->choice = 1;
        this->runMenu();
    }
}

void Menu::playerSelection(int i)
{
    string player_name;

    for (int x = 1; x < i + 1; x++)
    {
        if (x == i + 5)
        {
            cout << "Reached max player limit of 4" << endl;
            return;
        }
        cout << "Enter a name for player " << x << ": " << endl;
        cout << "> ";
        cin >> player_name;

        while (cin.fail() || player_name.find_first_of("0123456789") != string::npos)
        {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid name." << endl;
            cin >> player_name;
        }
        Player *tmp_p = new Player();
        tmp_p->setName(player_name);
        tmp_p->setScore(0);
        tmp_p->setPassCounter(0);
        players.push_back(tmp_p);
        cout << "Player" << x << " name set to: " << player_name << endl;
        cin.clear();
    }
    cout << endl;
}

bool Menu::isTwoPlayer()
{
    return true;
}

void Menu::newGame()
{
    // Player initializing
    cout << "Let's Play!" << endl;
    cout << endl;

    LinkedList *list = new LinkedList();
    TileBag *tb = new TileBag(list);
    GameBoard *gb = new GameBoard();

    cout << "Player 1 starts first." << endl;
    cout << endl;
    GameEngine *ge = new GameEngine(tb, players, gb);
    ge->gamePlay();
}

void Menu::loadGame(string inputFile)
{
    LinkedList *list = new LinkedList();
    TileBag *tb = new TileBag(list);
    GameBoard *gb = new GameBoard();

    ifstream gameData;

    players.~vector();

    gameData.open(inputFile);
    if (!gameData || gameData.fail())
    {
        cout << "Error loading game" << endl;
        this->runMenu();
    }

    // GET PLAYER COUNT
    int pl_count;
    gameData >> pl_count;
    // INTIALIZE PLAYERS
    string name;
    int score;
    int pass_count;

    string line;

    for (int i = 0; i < pl_count; i++)
    {
        Player *tmp_pl = new Player();
        // basic string
        gameData >> name;
        gameData >> score;
        gameData >> pass_count;
        // tiles
        getline(gameData >> ws, line);
        stringstream ss(line);
        int x = 0;
        for (int i = 0; i < 7; i++)
        {
            char tmp_char = line[0 + x];
            int tmp_value = line[2 + x] - '0';
            Tile *tmp_tl = new Tile(tmp_char, tmp_value);
            tmp_pl->addToHand(tmp_tl);
            x += 5;
        }
        // setters
        tmp_pl->setName(name);
        tmp_pl->setScore(score);
        tmp_pl->setPassCounter(pass_count);
        tmp_pl->printHand();
        players.push_back(tmp_pl);
    }

    // TileBag
    getline(gameData >> ws, line);
    stringstream ss(line);
    vector<Tile *> tile_bag;
    while (getline(ss, line, ','))
    {
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
        char tmp_tb_char = line[0];
        int tmp_tb_int = line[2] - '0';
        Tile *tmp_tile = new Tile(tmp_tb_char, tmp_tb_int);
        tile_bag.push_back(tmp_tile);
    }
    tb->~TileBag();
    int new_tb_size = tile_bag.size();
    for (int tl = 0; tl < new_tb_size; tl++)
    {
        tb->addBack(tile_bag[tl]);
    }

    // Skip lines
    for (int skip = 0; skip < 17; skip++)
    {
        getline(gameData, line);
    }
    GameEngine *ge = new GameEngine(tb, players, gb);
    // Board tiles
    line.clear();
    getline(gameData >> ws, line);
    stringstream ss2(line);
    while (getline(ss2, line, ','))
    {
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
        char tmp_board_char = line[0];
        char board_row_char = line[2];
        int board_col = line[3] - '0';
        int board_row = gb->boardRow.find(board_row_char)->second;
        Tile *tmp_board_tile = new Tile(tmp_board_char, ge->valueByLetter(tmp_board_char));

        gb->addTile(board_row, board_col, tmp_board_tile);
    }
    ge->gamePlay();
}