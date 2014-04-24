#pragma once

#include "string"

using namespace std;

class List
{
public:
  List();
  ~List();

  void add(int hash, string key, int amount);
  void remove(string key);
  int find(string key);
  int size();
  void print();

  struct ListElement
  {
    int hash;
    string key;
    int amount;
    ListElement *next;

    ListElement() {};
    ListElement(int _hash, string _key, int _amount, ListElement *_next)
    {
      hash = _hash;
      key = _key;
      amount = _amount;
      next = _next;
    }

  };

//private:
  ListElement *head;
};
