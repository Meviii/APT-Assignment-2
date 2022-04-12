#include "Tile.h"

#include <iostream>

Tile::Tile(Letter letter, Value value){
    this->letter = letter;
    this->value = value;
}

Tile::Tile(){}

Letter Tile::getLetter(){
    return this->letter;
}

Value Tile::getValue(){
    return this->value;
}