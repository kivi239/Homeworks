#pragma once
#include <cstdio>

///Class List with sorted elements
class List
{
public:
  List();
  ~List();

  void add(int value);
  void remove(int value);
  bool find(int value);
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
