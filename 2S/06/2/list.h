#pragma once
#include <cstdio>

///Class List with sorted elements
class List
{
public:
  List();
  ~List();

  void addToList(int value);
  void removeFromList(int value);
  bool findInList(int value);
  void print();
  int sizeOfList();

private:
  struct ListElement
  {
    int value;
    ListElement *next;
    ListElement() {}
    ListElement(int newValue)
    {
      value = newValue;
      next = nullptr;
    }
  };

  ListElement *head;
};
