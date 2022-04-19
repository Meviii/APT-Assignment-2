#include "../LinkedList.h"
#include "../Tile.h"
#include "../Menu.h"

#include <iostream>
#include <string>


int main(void){

    std::string player_name;

    player_name = "tdasgas";

    if (player_name.find_first_of("0123456789") == std::string::npos){
        std::cout << "cor" << std::endl;
    }

    // int size = player_name.size();
    // for (int i = 0; i < size; i++){
    //     if (!isalpha(player_name[i])){
    //         std::cout << "has int";
    //     }else{
    //         std::cout << "correct";
    //     }
    // }
    
    // std::cout << "> ";
    // std::getline(std::cin >> std::ws, input);
    // std::cout << "place c at c1" << std::endl;


    // std::cout << input.substr(0,6) << std::endl; // place
    // std::cout << input.substr(6,1) << std::endl; // c
    // std::cout << input.substr(8,3) << std::endl; // at
    // std::cout << input.substr(11,2) << std::endl; // c1
    // std::cout << input.substr(6,1).size() << std::endl;
    // std::cout << input.substr(11,2).size() << std::endl;

    // Menu* menu = new Menu();
    // std::string str = "place C at C1";

    // char letter_to_place;
    // int value_to_place;
    // std::string tile_letter_to_remove;
    // std::string arg;

    // std::vector<std::string> s;

    // s = menu->argTokenizer(str);

    // arg = s[0];
    // tile_letter_to_remove = s[1];

    // letter_to_place = s[3][0];
    // value_to_place = std::stoi(s[3].substr(1,2));

    // Tile* tst = new Tile((Letter) letter_to_place, tst->valueByLetter(letter_to_place));
    
    // std::cout << arg << std::endl;
    // std::cout << tile_letter_to_remove << std::endl;
    
    // std::cout << "Letter " << tst->getLetter() << std::endl;
    // std::cout << "Value " << tst->getValue() << std::endl;

    // std::cout << menu->argCounter(str) << std::endl;

    // std::cout << menu->boardRow.find('A')->second << std::endl;

    // std::string arg;
    // std::string tile_letter;
    // std::string tmp_holder;
    // std::string board_tile;

    // std::cin >> arg;
    // std::cin >> tile_letter;
    // std::cin >> tmp_holder;
    // std::cin >> board_tile;
    
    // std::string input = (arg + " " + tile_letter + " " + tmp_holder + " " + board_tile);

    // std::cout << input << std::endl;
}

