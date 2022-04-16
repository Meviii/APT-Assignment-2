#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <iostream>
#include <map>



// Define a Letter type
typedef char Letter;

// Define a Value type
typedef int Value;

class Tile {
   public:
      Letter letter;
      Value  value;
      Tile(Letter letter, Value value);
      Tile();
      
      Letter getLetter();
      Value  getValue();
      int valueByLetter(Letter letter);

   private:
      std::map<Letter, int> letterValue = {{'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4}, {'G', 2},
                                        {'H', 4}, {'I', 1}, {'J', 8}, {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1},
                                        {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1},
                                        {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4}, {'Z', 10}};
};

#endif // ASSIGN2_TILE_H
