#include "Player.h"

Player::Player(){
    
}

Player::Player(std::string name){
    this->name = name;
    this->score = 0;
}

int Player::getScore(){
    return score;
}

void Player::setScore(int Score){
    this->score = score;
}

std::string Player::getName(){
    return name;
}

void Player::setName(std::string name){
    this->name = name;
}