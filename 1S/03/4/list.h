#include <cstdio>

namespace Lists
{
  struct ListElement
  {
    int value;
    ListElement *next;
  };

  struct List
  {
    ListElement *head;
  };
  
  List create();
  void add(List &, int);
  void remove(List &, int);
  void print(List &);
  void deleteAll(ListElement *);
}
