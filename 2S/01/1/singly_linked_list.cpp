#include <cstdio>
#include "singly_linked_list.h"

SinglyLinkedList::SinglyLinkedList() : head(new ListElement(-1)) {}

SinglyLinkedList::~SinglyLinkedList()
{
  while (head != NULL)
  {
    ListElement *curElement = head->next;
    delete head;
    head = curElement;
  }
}

void SinglyLinkedList::add(int value)
{
  ListElement *curElement = head;
  while (curElement->next != NULL && curElement->next->value < value)
    curElement = curElement->next;
  ListElement *newElement = new ListElement;
  newElement->value = value;
  newElement->next = curElement->next;
  curElement->next = newElement;
}

void SinglyLinkedList::remove(int value)
{
  ListElement *curElement = head;
  while (curElement->next != NULL && curElement->next->value != value)
    curElement = curElement->next;
  if (curElement->next == NULL)
    return;

  ListElement *tmpElement = curElement->next;
  curElement->next = curElement->next->next;
  delete tmpElement;
}

void SinglyLinkedList::print()
{
  ListElement *curElement = head->next;
  while (curElement != NULL)
  {
    printf("%d ", curElement->value);
    curElement = curElement->next;
  }
  printf("\n");
}


int SinglyLinkedList::size()
{
  ListElement *curElement = head->next;
  int ans = 0;
  while (curElement != NULL)
  {
    ans++;
    curElement = curElement->next;
  }
  return ans;
}

