#include "stack.h"

class ArrayStack : Stack
{
public:
  ArrayStack();
  ~ArrayStack();

  void push(int newValue);
  int pop();
  int top();
  bool isEmpty();

private:
  int size;
  int occupied;
  int *arr;
};