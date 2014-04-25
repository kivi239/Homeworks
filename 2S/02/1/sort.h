#pragma once

///Class which is used to sort an array
class Sort
{
public:
  virtual ~Sort();
  ///Method which sorts an array
  virtual void sort(int *begin, int *end) = 0;
};
