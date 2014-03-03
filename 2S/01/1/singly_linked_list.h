#include <cstdio>
#include "list.h"

class SinglyLinkedList : List
{
public:
  SinglyLinkedList();
  ~SinglyLinkedList();

  void add(int value);
  void remove(int value);
  void print();

private:
  struct ListElement
  {
    int value;
    ListElement *next;
    ListElement() {}
    ListElement(int newValue) 
    {
      value = newValue;
      next = NULL;
    }
  };

  ListElement *head;
};
