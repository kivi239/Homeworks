#include <cstdio>
#include "char_stack.h"
#include <iostream>

using namespace std;

using namespace CharStacks;


CharStack CharStacks::create()
{
  CharStack s = {NULL};
  return s;
}

void CharStacks::push(CharStack &s, char value)
{
  CharStackElement *newElement = new CharStackElement;
  newElement->value = value;
  newElement->next = s.head;
  s.head = newElement;
}

char CharStacks::top(CharStack &s)
{
  if (s.head == NULL)
    return '!';
  return s.head->value;
}
        
char CharStacks::pop(CharStack &s)
{
  char result = top(s);
  CharStackElement *tmp = s.head;
  s.head = s.head->next;
  delete tmp;
  return result;
}

bool CharStacks::isEmpty(CharStack &s)
{
  return (s.head == NULL);
}
