#pragma once
#include <cstdio>

class List
{
public:
  List();
  ~List();

  void add(int value);
  void remove(int value);
  void print();
  int size();

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
