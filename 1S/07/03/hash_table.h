#include "list.h"

using namespace Lists;

namespace HashTables
{
  struct HashTable
  {
    int size;
    int occupied;

    List *ListArray;                                                 
  };

  HashTable create(int);
  void add(HashTable &, String &, int);
  int empty(HashTable &);
  double meanLength(HashTable &);
  List maxLength(HashTable &);
  void deleteAll(HashTable &);
  double loadFactor(HashTable &);
  HashTable makeBigger(HashTable &);
}      