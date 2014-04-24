#include "hash_table.h"
#include "list.h"

HashTable::HashTable() : size(1), occupied(0), all(0), listArray(new List[1]), hashFunction(new PolynomialHash()) {}

HashTable::HashTable(int newSize) : size(newSize), occupied(0), all(0), listArray(new List[newSize]),  hashFunction(new PolynomialHash()) {}

HashTable::HashTable(int newSize, int numHash) : size(newSize), occupied(0), all(0), listArray( new List[newSize])
{
  if (numHash == polynomialCode)
    hashFunction = new PolynomialHash();
  else
    hashFunction = new SimpleHash();
}

HashTable::~HashTable()
{
  delete hashFunction;
  delete[] listArray;
}

void HashTable::add(string key, int amount)
{
  int hash = hashFunction->getHash(key) % size;
  all += amount;
  if (!listArray[hash].find(key))
    occupied++;
  listArray[hash].add(hash, key, amount);

  if (loadFactor() > 5)
  {
    int newSize = size * 2;

    List *tempArray = new List[newSize];
    for (int i = 0; i < size; i++)
    {
      List::ListElement *curElement = listArray[i].head->next;
      while (curElement != nullptr)
      {
        tempArray[hashFunction->getHash(curElement->key) % newSize].add(hashFunction->getHash(curElement->key), curElement->key, curElement->amount);
        curElement = curElement->next;
      }
    }

    delete[] listArray;
    listArray = tempArray;
    size = newSize;
  }
}

void HashTable::remove(string key)
{
  if (!this->find(key))
    return;

  int hash = hashFunction->getHash(key) % size;
  occupied--;
  all -= listArray[hash].find(key);
  listArray[hash].remove(key);
}

bool HashTable::find(string key)
{
  int hash = hashFunction->getHash(key);
  return listArray[hash].find(key);
}

double HashTable::loadFactor()
{
  return occupied * 1.0 / size;
}

int HashTable::getSize()
{
  return size;
}

int HashTable::getOccupied()
{
  return occupied;
}

int HashTable::getAll()
{
  return all;
}

void HashTable::setHash(int number)
{
  if (hashFunction->number() == number)
    return;

  int newNum = 1 - hashFunction->number();
  delete hashFunction;
  if (newNum == simpleCode)
    hashFunction = new SimpleHash();
  else
    hashFunction = new PolynomialHash();

  List *tempArray = new List[size];
  for (int i = 0; i < size; i++)
  {
    List::ListElement *curElement = listArray[i].head->next;
    while (curElement != nullptr)
    {
      int hash = hashFunction->getHash(curElement->key);
      tempArray[hash % size].add(hash, curElement->key, curElement->amount);
      curElement = curElement->next;
    }
  }

  delete[] listArray;
  listArray = tempArray;
}

int HashTable::maxSize()
{
  int result = 0;
  for (int i = 0; i < size; i++)
    result = max(result, listArray[i].size());

  return result;
}

void HashTable::showStatistics()
{
  cout << "\n\n***\n";
  cout << "size: " << size << endl;
  cout << "different strings: " << occupied << endl;
  cout << "all strings: " << all << endl;
  cout << "load factor: " << this->loadFactor() << endl;
  cout << "\n***\n\n";
}
