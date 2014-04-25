#include "stack.h"

class PointerStack : public Stack
{
public:
  PointerStack();
  ~PointerStack();

  void push(int newValue);
  int pop();
  int top();
  bool isEmpty();

private:
  struct StackElement
  {
    int value;
    StackElement* next;
  };

  StackElement *head;
};
