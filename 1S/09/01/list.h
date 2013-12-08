#include "String.h"

using namespace Strings;

namespace Lists
{
  struct ListElement
  {
    int hash;
    String key;
    int amount;
    ListElement *next;
  };

  struct List
  {
    ListElement *head;
  };
  
  List create();
  bool addTriple(List &, int, String &, int);
  void remove(List &, String &);
  void deleteAll(List &);
  int size(List &);
  void print(List &);
  bool find(List &, String &);
}
