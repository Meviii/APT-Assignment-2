#include "Player.h"

Player::Player(){
    hand = new LinkedList();
}

Player::Player(std::string name, LinkedList* tile_hand){
    this->name = name;
    this->score = 0;
    this->hand = tile_hand;
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

void Player::setHand(TileBag* tb){
    for(int i = 0; i < PLAYER_HAND_AMOUNT; i++){
        this->hand->addBack(tb->getFront());
        tb->removeFront();
    }
    return;
}

LinkedList* Player::getHand(){
    return hand;
}

void Player::printHand(){
    std::cout << "Your hand is: " << std::endl;

    Node* h = hand->getHead();
    for (int i = 0; i < PLAYER_HAND_AMOUNT; i++){
        if (i == (PLAYER_HAND_AMOUNT-1)){
            std::cout << h->tile->getLetter() << "-" << h->tile->getValue();
        }else{
            std::cout << h->tile->getLetter() << "-" << h->tile->getValue() << ", ";
        }
        h = h->next;
    }
    std::cout << std::endl;
}

Tile* Player::getTileInHand(Letter letter){
    Node* h = this->hand->getHead();
    Tile* toRet;
    while (h != nullptr){
        if (h->tile->getLetter() == letter){
            toRet = new Tile(h->tile->getLetter(), h->tile->getValue());
            return toRet;
        }else{
            h = h->next;
        }
    }
    return 0;
}

bool Player::isTileInHand(Tile* tile){
    return false;
}