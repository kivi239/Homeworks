#include "arrayStack.h"

const int firstSize = 128;

ArrayStack::ArrayStack() : size(firstSize), occupied(0), arr(new int[128]) {}

ArrayStack::~ArrayStack()
{
  delete[] arr;
}

void ArrayStack::push(int newValue)
{
  if (size == occupied)
  {
    int *newArr = new int[size * 2];
    for (int i = 0; i < size; i++)
      newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    size *= 2;
  }
  arr[occupied++] = newValue;
}

int ArrayStack::pop()
{
  int result = this->top();
  if (occupied > 0)
    occupied--;
  return result;
}

int ArrayStack::top()
{
  if (occupied == 0)
    return -(1e9 + 43);
  return arr[occupied - 1];
}

bool ArrayStack::isEmpty()
{
  return occupied == 0;
}


