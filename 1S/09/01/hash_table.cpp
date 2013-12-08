#include "hash_table.h"
#include <algorithm>
#include <cstdio>

using namespace HashTables;
using std::max;

const int firstSize = 1123;

HashTable HashTables::create(int size)
{
  size = max(size, firstSize);
  List *ListArray = new List[size];
  for (int i = 0; i < size; i++)
    ListArray[i] = Lists::create();
                   
  HashTable newTable = {size, 0, ListArray};

  return newTable;
}

void HashTables::add(HashTable &table, String &key, int amount)                                                                                            
{
  int hash = hashValue(key, table.size);
  if (addTriple(table.ListArray[hash], hash, key, amount))
    table.occupied++;
}

int HashTables::empty(HashTable &table)
{
  int answer = 0;
  for (int i = 0; i < table.size; i++)
    if (size(table.ListArray[i]) == 0)
      answer++;
    
  return answer;
}

double HashTables::meanLength(HashTable &table)
{
  double sum = 0;
  for (int i = 0; i < table.size; i++)                                      
    sum += size(table.ListArray[i]);

  return sum / table.size;
}

List HashTables::maxLength(HashTable &table)                                                          
{
  List curList = table.ListArray[0];
  for (int i = 1; i < table.size; i++)
  {
    if (size(curList) < size(table.ListArray[i]))
      curList = table.ListArray[i];
  }

  return curList;
}

void HashTables::deleteAll(HashTable &table)
{
  for (int i = 0; i < table.size; i++)
    Lists::deleteAll(table.ListArray[i]);
  delete[] table.ListArray;
}

double HashTables::loadFactor(HashTable &table)
{
  return table.occupied * 1.0 / table.size;
}
        
HashTable HashTables::makeBigger(HashTable &table)
{
  int newSize = table.size * 2;
  HashTable newTable = create(newSize);

  for (int i = 0; i < table.size; i++)
  {
    ListElement *curElement = table.ListArray[i].head;
    while (curElement->next != NULL)
    {
      curElement = curElement->next;
      String newStr = clone(curElement->key);
      add(newTable, newStr, curElement->amount);
    }
  }
  deleteAll(table);                                                             

  return newTable;
}

bool HashTables::find(HashTable &table, String &str)
{
  int hash = hashValue(str, table.size);
  return Lists::find(table.ListArray[hash], str);
}

void HashTables::remove(HashTable &table, String &str)
{
  int hash = hashValue(str, table.size);
  Lists::remove(table.ListArray[hash], str);
}