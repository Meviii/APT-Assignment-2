
#include "LinkedList.h"

#include <iostream>
#include <string>

LinkedList::LinkedList() {
   head = nullptr;
   tail = nullptr;
   size = 0;
   // TODO
}

LinkedList::~LinkedList() {
   while (head != nullptr){
      Node* cur = head->next;
      delete head;
      head = cur;
   }
   size = 0;
}

int LinkedList::getSize(){
   return size;
}

Node* LinkedList::getHead(){
   return head;
}

void LinkedList::addBack(Tile* node){
   Node* newNode = new Node(node, nullptr);

   if (head == nullptr){
      head = newNode;
   }else{
      Node* tmp = head;

      while(tmp->next != nullptr){
         tmp = tmp->next;
      }
      tmp->next = newNode;
   }
   size++;
}

void LinkedList::addFront(Tile* node){
   Node* newNode = new Node(node, head);

   if (head == nullptr){
      head = newNode;
   }else{
      //head->next = head;
      head = newNode;
   }
   size++;
}

Node *LinkedList::getNode(int i)
{
   int counter = 0;
   Node* tmp = head;
   if (i >= 0 && i <= size){
      while (counter != i && tmp != nullptr){
         tmp = tmp->next;
         counter++;
      }
   }else{
      Node* t = nullptr;
      std::cout << "Node not in range" << std::endl;
      return t;
   }

   return tmp;
}


bool LinkedList::checkEmpty(){
   return head == nullptr;
}

void LinkedList::removeNode(int i){

   if (i == 0){
      if (head == nullptr){
         return;
      }else{
         Node* tmp = head;
         head = head->next;
         delete tmp;
         return;
      }
   }else if (i > 0 && i < size){
      Node* n = getNode(i-1);
      Node* n1 = getNode(i+1);
      n-> next = n1;
      size++;
   }else if (i == size){
      this->tail = nullptr;
   }
   size--;
}


void LinkedList::printList(){
   std::cout << "Linked List with tile size: " << size << std::endl;
   struct Node* tmp = head;
   while (tmp != NULL){
      std::cout << "Letter: " << tmp->tile->getLetter() << ", Value: " << tmp->tile->getValue() << std::endl;
      tmp = tmp->next;
   }
}