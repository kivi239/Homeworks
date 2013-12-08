#include <cstdio>
#include "double_stack.h"

using namespace DoubleStacks;

DoubleStack DoubleStacks::create()
{
  DoubleStack s = {NULL};
  return s;
}

void DoubleStacks::push(DoubleStack &s, double value)
{
  DoubleStackElement *newElement = new DoubleStackElement;
  newElement->value = value;
  newElement->next = s.head;                                                                   
  s.head = newElement;
}

double DoubleStacks::top(DoubleStack &s)
{
  if (s.head == NULL)
    return '!';
  return s.head->value;
}
        
double DoubleStacks::pop(DoubleStack &s)
{
  double result = top(s);
  DoubleStackElement *tmp = s.head;
  s.head = s.head->next;
  delete tmp;
  return result;
}

int DoubleStacks::size(DoubleStack &s)
{
  if (s.head == NULL)
    return 0;
  DoubleStackElement *curElement = s.head;
  int cnt = 0;
  while (curElement->next != NULL)
  {
    cnt++;
    curElement = curElement->next;
  }
  return cnt + 1;
}
