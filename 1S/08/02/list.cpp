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

void Lists::add(List &l, int vertex, int length)
{                                                                                                                   
  ListElement *curElement = l.head;
  ListElement *newElement = new ListElement;
  newElement->vertex = vertex;
  newElement->length = length;
  newElement->next = curElement->next;
  curElement->next = newElement;
}

void Lists::print(List &l)
{                                                                                   
  ListElement *curElement = l.head->next;
  while (curElement != NULL)
  {
    printf("%d %d\n", curElement->vertex, curElement->length);
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

int size(ListElement *curElement)
{
  if (curElement == NULL)
    return 0;

  return 1 + size(curElement->next);
}

int Lists::size(List &l)
{
  return ::size(l.head) - 1;
}

