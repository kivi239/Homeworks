#include <QCoreApplication>
#include "linkedlist.h"
#include "listonarray.h"
#include <iostream>

int main()
{
    //Список на указателях
    LinkedList * linkedList = new LinkedList();
    linkedList->insert(0, new ListElement(5));
    linkedList->insert(0, new ListElement(2));
    std::cout << linkedList->length();
    linkedList->printList();
    std::cout << "\n";
    linkedList->deleteElement(0);
    linkedList->printList();
    linkedList->deleteList();
    std::cout << "\n\n";
    delete linkedList;

    //Список на массивах
    ListOnArray * listOnArray = new ListOnArray();
    ListElement * le1 = new ListElement(5);
    ListElement * le2 = new ListElement(2);
    listOnArray->insert(0, le1);
    listOnArray->insert(0, le2);

    delete le1;
    delete le2;

    std::cout << listOnArray->length();
    listOnArray->printList();
    std::cout << "\n";
    listOnArray->deleteElement(0);
    listOnArray->printList();
    listOnArray->deleteList();
    delete listOnArray;

    return 0;
}
