#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once
#include "list.h"

class LinkedList : public List
{
public:
    LinkedList();
    ~LinkedList();
    void printList();
    int length();
    void insert(int position, ListElement * newElement);
    void deleteElement(int position);
    void deleteList();
private:
    LinkedList * next;
};

#endif // LINKEDLIST_H
