#include "list.h"

class DoublyLinkedList : List
{
public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void add(int value);
  void remove(int value);
  void print();

private:
  struct ListElement
  {
    int value;
    ListElement *next;
    ListElement *prev;
  };

  ListElement *head;
};
