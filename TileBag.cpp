#include "TileBag.h"

#include <random>
#include <fstream>
#include <iostream>

TileBag::TileBag(){
    this->tile_list = nullptr;
}

TileBag::TileBag(LinkedList* tile_list){
    this->tile_list = tile_list;
}

TileBag::~TileBag(){

}

void TileBag::setAsList(LinkedList* tile_list){
    this->tile_list = tile_list;
}

LinkedList* TileBag::getList(){
    return tile_list;
}

int TileBag::getSize(){
    return tile_list->getSize();
}

Tile* TileBag::getTile(int i){
    return tile_list->getNodeAsTile(i);
}

Tile* TileBag::getFront(){
    return tile_list->getNodeAsTile(0);
}

void TileBag::addBack(Tile* tile){
    tile_list->addBack(tile);
}

void TileBag::remove(int i){
    tile_list->removeNode(i);
}

void TileBag::removeFront(){
    tile_list->removeNode(0);
}

void TileBag::removeBack(){
    tile_list->removeBack();
}

