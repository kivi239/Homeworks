#include <cstdio>
#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList()
{
  head = new ListElement;
  head->value = -1;
  head->next = NULL;
  head->prev = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
  while (head != NULL)
  {
    ListElement *curElement = head->next;
    delete head;
    head = curElement;
  } 
}

void DoublyLinkedList::add(int value)
{
  ListElement *curElement = head;
  while (curElement->next != NULL && curElement->next->value < value)
    curElement = curElement->next;
  ListElement *newElement = new ListElement;
  newElement->value = value;
  
  newElement->next = curElement->next;
  if (curElement->next != NULL)
    curElement->next->prev = newElement;
  
  curElement->next = newElement;
  newElement->prev = curElement;
}

void DoublyLinkedList::remove(int value)
{
  ListElement *curElement = head;
  while (curElement->next != NULL && curElement->next->value != value)
    curElement = curElement->next;
  if (curElement->next == NULL)
    return;

  ListElement *tmpElement = curElement->next;
  curElement->next = curElement->next->next;
  if (curElement->next->next != NULL)
    curElement->next->next->prev = curElement->next;
  
  delete tmpElement;
}

void DoublyLinkedList::print()
{                                                                                   
  ListElement *curElement = head->next;
  while (curElement != NULL)
  {
    printf("%d ", curElement->value);
    curElement = curElement->next;
  }
  printf("\n");
}
