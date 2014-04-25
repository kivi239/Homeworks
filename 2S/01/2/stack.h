#pragma once

class Stack
{
public:
  virtual ~Stack() = 0;

  virtual void push(int newValue) = 0;
  virtual int pop() = 0;
  virtual int top() = 0;
  virtual bool isEmpty() = 0;
};

