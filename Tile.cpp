#include "Tile.h"

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

int Tile::valueByLetter(Letter letter){
    return letterValue.find(letter)->second;
}