#include "polynomial_hash.h"
#include "simple_hash.h"
#include "list.h"

class HashTable
{
public:
  HashTable();
  HashTable(int newSize);
  HashTable(int newSize, int numHash);
  ~HashTable();

  void add(string key, int amount);
  void remove(string key);
  bool find(string key);
  double loadFactor();
  int maxSize();
  void setHash(int number);
  void showStatistics();
  int getSize();
  int getOccupied();
  int getAll();

private:
  int size;
  int occupied;
  int all;
  List *listArray;
  HashFunction *hashFunction;
};
