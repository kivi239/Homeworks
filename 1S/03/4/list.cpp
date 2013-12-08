#include <cstdio>
#include "list.h"

using namespace Lists;

List Lists::create()
{
  List l = {NULL};
  l.head = new ListElement;
  l.head->next = NULL;                                   
  return l;
}

void Lists::add(List &l, int value)
{
  ListElement *curElement = l.head;
  while (curElement->next != NULL && curElement->next->value < value)
    curElement = curElement->next;
  ListElement *newElement = new ListElement;
  newElement->value = value;
  newElement->next = curElement->next;
  curElement->next = newElement;
}

void Lists::remove(List &l, int value)
{
  ListElement *curElement = l.head;
  while (curElement->next != NULL && curElement->next->value != value)
    curElement = curElement->next;
  if (curElement->next == NULL)
    return;

  ListElement *tmpElement = curElement->next;
  curElement->next = curElement->next->next;
  delete tmpElement;
}

void Lists::print(List &l)
{                                                                                   
  ListElement *curElement = l.head->next;
  while (curElement != NULL)
  {
    printf("%d ", curElement->value);
    curElement = curElement->next;
  }
  printf("\n");
}

void Lists::deleteAll(ListElement *curElement)
{
  if (curElement != NULL)
  {
    deleteAll(curElement->next);
    delete curElement;
  }                                                      
}

