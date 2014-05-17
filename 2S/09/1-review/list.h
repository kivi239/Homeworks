#ifndef LIST_H
#define LIST_H

#pragma once
#include "listelement.h"

class List
{
public:
    virtual void printList() = 0;
    virtual int length() = 0;
    virtual void insert(int position, ListElement * newElement) = 0;
    virtual void deleteElement(int position) = 0;
    virtual void deleteList() = 0;
protected:
    ListElement * head;
};

#endif // LIST_H
