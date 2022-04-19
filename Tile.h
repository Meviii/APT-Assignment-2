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

   private:
};

#endif // ASSIGN2_TILE_H
