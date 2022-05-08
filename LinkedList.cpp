
#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList()
{
   head = nullptr;
   tail = nullptr;
   size = 0;
   // TODO
}

LinkedList::~LinkedList()
{
   while (head != nullptr)
   {
      Node *cur = head->next;
      delete head;
      head = cur;
   }
   size = 0;
}

int LinkedList::getSize()
{
   return size;
}

Node *LinkedList::getHead()
{
   return head;
}

void LinkedList::addBack(Tile *node)
{
   Node *newNode = new Node(node, nullptr);

   if (head == nullptr)
   {
      head = newNode;
   }
   else
   {
      Node *tmp = head;

      while (tmp->next != nullptr)
      {
         tmp = tmp->next;
      }
      tmp->next = newNode;
   }
   size++;
}

void LinkedList::addFront(Tile *node)
{
   Node *newNode = new Node(node, head);

   if (head == nullptr)
   {
      head = newNode;
   }
   else
   {
      // head->next = head;
      head = newNode;
   }
   size++;
}

void LinkedList::removeBack()
{
   this->removeNode(size);
}

Node *LinkedList::getNode(int i)
{
   int counter = 0;
   Node *node = head;
   if (i >= 0 && i <= size)
   {
      while (counter != i && node != nullptr)
      {
         node = node->next;
         counter++;
      }
   }
   else
   {
      Node *t = nullptr;
      cout << "Node not in range" << endl;
      return t;
   }

   return node;
}

Tile *LinkedList::getNodeAsTile(int i)
{
   int counter = 0;
   Node *cur = head;
   Tile *ret = nullptr;

   if (i >= 0 && i <= size)
   {
      while (counter != i && cur != nullptr)
      {
         cur = cur->next;
         counter++;
      }
   }
   else
   {
      cout << "Node not in range" << endl;
      return ret;
   }
   ret = new Tile(cur->tile->getLetter(), cur->tile->getValue());
   return ret;
}

bool LinkedList::checkEmpty()
{
   return head == nullptr;
}

void LinkedList::removeNode(int i)
{

   if (i == 0)
   {
      if (head == nullptr)
      {
         return;
      }
      else
      {
         Node *tmp = head;
         head = head->next;
         size--;
         delete tmp;
         return;
      }
   }
   else if (i > 0 && i < size)
   {
      Node *n = getNode(i - 1);
      Node *n1 = getNode(i + 1);
      n->next = n1;
      size++;
   }
   else if (i == size)
   {
      this->tail = nullptr;
   }
   else
   {
      cout << "not in range" << endl;
      return;
   }
   size--;
}

void LinkedList::printList()
{
   cout << "Linked List with tile size: " << size << endl;
   struct Node *tmp = head;
   while (tmp != NULL)
   {
      cout << "Letter: " << tmp->tile->getLetter() << ", Value: " << tmp->tile->getValue() << endl;
      tmp = tmp->next;
   }
}