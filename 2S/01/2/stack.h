#pragma once

class Stack
{
public:
  Stack();
  virtual ~Stack() = 0;
  
  virtual void push(int newValue) = 0;
  virtual int pop() = 0;
  virtual int top() = 0;
  virtual bool isEmpty() = 0;

};

