#pragma once

class Sort
{
public:
  Sort();
  virtual ~Sort();

  virtual void sort(int *begin, int *end) = 0;
};