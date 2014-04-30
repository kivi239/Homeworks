#include <cstdio>
#include "list.h"
#include "excAddElement.h"
#include "excDeleteElement.h"

List::List() : head(new ListElement(-1)) {}

List::~List()
{
  while (head != nullptr)
  {
    ListElement *curElement = head->next;
    delete head;
    head = curElement;
  }
}

void List::add(int value)
{ 
  ListElement *curElement = head;
  while (curElement->next != nullptr && curElement->next->value < value)
    curElement = curElement->next;

  if (curElement->next != nullptr && curElement->next->value == value)
    throw ExcAddElement("This element already exists in list!");

  ListElement *newElement = new ListElement;
  newElement->value = value;
  newElement->next = curElement->next;
  curElement->next = newElement;
}

void List::remove(int value)
{
  ListElement *curElement = head;
  while (curElement->next != nullptr && curElement->next->value != value)
    curElement = curElement->next;
  if (curElement->next == nullptr)
    throw ExcDeleteElement("This element doesn't exist in list!");

  ListElement *tmpElement = curElement->next;
  curElement->next = curElement->next->next;
  delete tmpElement;
}

void List::print()
{
  ListElement *curElement = head->next;
  while (curElement != nullptr)
  {
    printf("%d ", curElement->value);
    curElement = curElement->next;
  }
  printf("\n");
}


int List::size()
{
  ListElement *curElement = head->next;
  int ans = 0;
  while (curElement != nullptr)
  {
    ans++;
    curElement = curElement->next;
  }
  return ans;
}


