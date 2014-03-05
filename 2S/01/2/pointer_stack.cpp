#include "pointer_stack.h"
#include <cstdio>

PointerStack::PointerStack() : head(nullptr) {}

PointerStack::~PointerStack() 
{                               
  while (head != NULL)                                                    
  {
    StackElement *curElement = head->next;
    delete head;
    head = curElement;
  }
}

void PointerStack::push(int newValue) 
{
  StackElement *newElement = new StackElement;
  newElement->value = newValue;
  newElement->next = head;
  head = newElement;
}

int PointerStack::top()
{
  if (head == nullptr)
    return (int)'!';
  return head->value;
}
        
int PointerStack::pop()
{
  int result = this->top();
  StackElement *tmp = head;
  head = head->next;                                                                
  delete tmp;
  return result;
}

bool PointerStack::isEmpty()
{
  return (head == nullptr);
}
