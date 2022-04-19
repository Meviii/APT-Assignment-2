#include "../LinkedList.h"
#include "../Tile.h"
#include "../TileBag.h"

#include <iostream>
#include <random>
#include <fstream>

void printList(TileBag* tb);
void basicFunctions(TileBag* tb);
void printFirstFive(TileBag* tb);
void printLastFive(TileBag* tb);

int main(void){
    
    LinkedList* list = new LinkedList();
    TileBag* tb = new TileBag(list);

    //tb->readFile()

    //tb->shuffle();
    //printList(tb);

    basicFunctions(tb);
    return 0;
}

void basicFunctions(TileBag* tb){

    int size = tb->getSize();

    std::cout << "Size of bag:" << tb->getSize() << std::endl;
    std::cout << "getFront:" << tb->getFront()->getLetter() << std::endl;

    std::cout << "=============================" << std::endl;

    Tile* t1 = new Tile('Z',100);
    tb->addBack(t1);
    std::cout << "getTile['Z',100]: " << tb->getTile(size)->getValue() << std::endl;

    std::cout << "=============================" << std::endl;

    std::cout << "Remove ['Z',100]" << std::endl;
    tb->remove(size-1);
    std::cout << tb->getTile(size-1)->getLetter() << std::endl;

    std::cout << "=============================" << std::endl;

    printLastFive(tb);
    std::cout << "Remove back" << std::endl;
    tb->removeBack();
    printLastFive(tb);

    std::cout << "=============================" << std::endl;

    printFirstFive(tb);
    std::cout << "Remove front" << std::endl;
    tb->removeFront();
    printFirstFive(tb);
}

void printList(TileBag* tb){
    for (int i = 0; i < tb->getSize(); i++){
        std::cout << tb->getTile(i)->getLetter();
        std::cout << ", ";
        std::cout << tb->getTile(i)->getValue();
        std::cout << std::endl;
    }
}

void printLastFive(TileBag* tb){
    std::cout << " >> Printing last 5 elements << " << std::endl;
    for (int i = 94; i < (tb->getSize()-1); i++){
        std::cout << tb->getTile(i)->getLetter();
        std::cout << ", ";
        std::cout << tb->getTile(i)->getValue();
        std::cout << std::endl;
    }
}

void printFirstFive(TileBag* tb){
    std::cout << " >> Printing first 5 elements << " << std::endl;
    for (int i = 0; i < 5; i++){
        std::cout << tb->getTile(i)->getLetter();
        std::cout << ", ";
        std::cout << tb->getTile(i)->getValue();
        std::cout << std::endl;
    }
}