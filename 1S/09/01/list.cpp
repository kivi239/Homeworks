#include <cstdio>
#include <cstring>
#include "list.h"
#include <iostream>

using namespace std;

using namespace Lists;

List Lists::create()
{
  List l = {NULL};
  l.head = new ListElement;
  l.head->hash = -1;
  char tmp[1] = {'\0'};
  String str = Strings::create(tmp, 0);
  l.head->key = str;
  l.head->next = NULL;                                   
  return l;
}

bool Lists::addTriple(List &l, int hash, String &key, int amount)
{
  ListElement *curElement = l.head;
  while (curElement->next != NULL && !areEqual(curElement->next->key, key))
    curElement = curElement->next;

  if (curElement->next != NULL)
  {
    curElement->next->amount += amount;
    remove(key);
    return false;   
  }
  ListElement *newElement = new ListElement;
  newElement->hash = hash;
  newElement->key = key;
  newElement->amount = 1;
  newElement->next = curElement->next;
  curElement->next = newElement;
  return true;
}

void Lists::remove(List &l, String &str)
{
  ListElement *curElement = l.head;
  while (curElement->next != NULL && !areEqual(curElement->next->key, str))
    curElement = curElement->next;
  if (curElement->next == NULL)
    return;

  ListElement *tmpElement = curElement->next;
  curElement->next = curElement->next->next;

  remove(tmpElement->key);
  delete tmpElement;
}

void Lists::print(List &l)
{                                                                                   
  ListElement *curElement = l.head->next;
  
  int cnt = 0;
  while (curElement != NULL)
  {
    printf("\"");
    print(curElement->key);
    printf("\" with hash value %d\n", curElement->hash);
    curElement = curElement->next;
    cnt++;
  }
} 

void deleteAll(ListElement *curElement)
{
  if (curElement != NULL)
  {
    deleteAll(curElement->next);
    remove(curElement->key);
    delete curElement;
  }
}

void Lists::deleteAll(List &l)
{
  ::deleteAll(l.head);                                                      
}                                                                 

int Lists::size(List &l)
{
  ListElement *curElement = l.head;
  int answer = 0;
  while (curElement->next != NULL)
  {
    answer++;
    curElement = curElement->next;
  }
  return answer;
}
                                            
bool Lists::find(List &l, String &str)
{
  ListElement *curElement = l.head;
  while (curElement->next != NULL)
  {
    curElement = curElement->next;
    if (areEqual(curElement->key, str))
      return true;
  }
  return false;
}
