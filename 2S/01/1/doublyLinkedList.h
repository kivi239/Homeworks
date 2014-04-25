#include <cstdio>
#include "list.h"

class DoublyLinkedList : public List
{
public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void add(int value);
  void remove(int value);
  void print();
  int size();

private:
  struct ListElement
  {
    int value;
    ListElement *next;
    ListElement *prev;
    ListElement() {}
    ListElement(int newValue)
    {
      value = newValue;
      next = NULL;
      prev = NULL;
    }
  };

  ListElement *head;
};
