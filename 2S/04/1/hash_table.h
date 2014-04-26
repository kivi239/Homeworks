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
  void remove(const string &key);
  bool find(string key);
  double loadFactor();
  ///Method which returns maximum length of list in hash table
  int maxSize();
  ///Method which can change hash function
  void setHash(int number);
  void showStatistics();
  ///Property which returns size of hash table
  int getSize();
  ///Property which returns number of different strings in hash table
  int getOccupied();
  ///Property which returns number of all strings in hash table
  int getAll();

private:
  int size;
  int occupied;
  int all;
  List *listArray;
  HashFunction *hashFunction;
};
