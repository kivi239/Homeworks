#pragma once

class List
{
public:
  List();
  ~List();
  virtual void add(int value) = 0;
  virtual void remove(int value) = 0;
  virtual void print() = 0;
};
