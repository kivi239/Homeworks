#include <cstdio>
#include <cstring>
#include "list.h"

using namespace Lists;

List Lists::create()
{
  List l = {NULL};
  l.head = new ListElement;
  l.head->hash = -1;
  l.head->next = NULL;                                   
  return l;
}

void Lists::addTriple(List &l, int hash, String &key, int amount)
{
  ListElement *curElement = l.head;
  while (curElement->next != NULL && !areEqual(curElement->next->key, key))
    curElement = curElement->next;
  
  if (curElement->next != NULL)
  {
    curElement->next->amount += amount;
    return;   
  }
  ListElement *newElement = new ListElement;
  newElement->hash = hash;
  newElement->key = clone(key);
  newElement->amount = amount;
  newElement->next = curElement->next;
  curElement->next = newElement;
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
    if (curElement->hash != -1)
      Strings::remove(curElement->key);
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
                                            
