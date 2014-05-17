#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList() : List()
{
    this->head = new ListElement(-1);
    this->next = nullptr;
}

LinkedList::~LinkedList()
{
    this->deleteList();
}

void LinkedList::printList(){
    LinkedList * list = this->next;
    while(list != nullptr)
    {
        list->head->printElement();
        std::cout << "; ";
        list = list->next;
    }
}

int LinkedList::length()
{
    int result = 0;

    LinkedList * list = this->next;
    while(list != nullptr)
    {
        result++;
        list = list->next;
    }

    return result;
}

void LinkedList::insert(int position, ListElement * newElement)
{
    LinkedList * list = this;
    while(list->next != nullptr && position > 0)
    {
        position--;
        list = list->next;
    }

    if (position != 0)
    {
        std::cerr << "Error. The index is more then the length";
        this->deleteList();
        exit(0);
    }

    LinkedList * newList = new LinkedList();
    newList->head = newElement;
    newList->next = list->next;
    list->next = newList;
}

void LinkedList::deleteElement(int position)
{
    LinkedList * list = this;
    while(list->next != nullptr && position > 0)
    {
        position--;
        list = list->next;
    }

    if (list->next == nullptr || position > 0)
    {
        std::cerr << "Error. The index is no element with this index";
        this->deleteList();
        exit(0);
    }

    LinkedList * newList = list->next;
    list->next = list->next->next;
    delete newList->head;
}

void LinkedList::deleteList()
{
    int length = this->length();
    while(length > 0)
    {
        this->deleteElement(0);
        length--;
    }
    delete this->head;
}
