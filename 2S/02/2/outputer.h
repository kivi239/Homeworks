#pragma once

class Outputer
{
public:
  virtual ~Outputer();

  virtual void out(int **a, int n) = 0;
};