#include <iostream>
#include "list.h"

List::List() : head(new ListElement(0, "?", 0, nullptr)) {}

void deleteAll(List::ListElement *curElement)
{
  if (curElement != nullptr)
  {
    deleteAll(curElement->next);
    delete curElement;
  }
}

List::~List()
{
  deleteAll(head);
}

void List::add(int hash, string key, int amount)
{
  ListElement *curElement = head;
  while (curElement->next != nullptr && curElement->next->key != key)
    curElement = curElement->next;

  if (curElement->next != nullptr)
  {
    curElement->next->amount += amount;
    return;
  }
  ListElement *newElement = new ListElement(hash, key, amount, curElement->next);
  curElement->next = newElement;
}

void List::remove(string str)
{
  ListElement *curElement = head;
  while (curElement->next != nullptr && curElement->next->key != str)
    curElement = curElement->next;
  if (curElement->next == nullptr)
    return;

  ListElement *tmpElement = curElement->next;
  curElement->next = curElement->next->next;

  delete tmpElement;
}

int List::find(string str)
{
  ListElement *curElement = head;
  while (curElement->next != nullptr && curElement->next->key != str)
    curElement = curElement->next;

  if (curElement->next == nullptr)
    return 0;
  return curElement->next->amount;
}

void List::print()
{
  ListElement *curElement = head->next;

  int cnt = 0;
  while (curElement != nullptr)
  {
    cout << "\"" << curElement->key << "\" with hash value " << curElement->hash << endl;
    curElement = curElement->next;
    cnt++;
  }
}

int List::size()
{
  ListElement *curElement = head;
  int answer = 0;
  while (curElement->next != nullptr)
  {
    answer++;
    curElement = curElement->next;
  }
  return answer;
}


