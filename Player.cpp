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

void Player::assignHand(std::vector<Tile*> player_hand, TileBag* tb){
    for(int i = 0; i < PLAYER_HAND_AMOUNT; i++){
        _player_hand.push_back(tb->getFront());
        player_hand.push_back(tb->getFront());
        tb->removeFront();
    }
}

std::vector<Tile*> Player::getHand(){
    return _player_hand;
}

void Player::printHand(){
    std::cout << "Your hand is: " << std::endl;
    for (int i = 0; i < PLAYER_HAND_AMOUNT; i++){
        if (i == (PLAYER_HAND_AMOUNT-1)){
            std::cout << _player_hand[i]->getLetter() << "-" << _player_hand[i]->getValue();
        }else{
            std::cout << _player_hand[i]->getLetter() << "-" << _player_hand[i]->getValue() << ", ";
        }
    }
    std::cout << std::endl;
}

bool Player::isTileInHand(Tile* tile){
    int size = _player_hand.size();
    for (int i = 0; i < size; i++){
        if (tile == _player_hand[i]){
            return true;
        }
    }
    return false;
}