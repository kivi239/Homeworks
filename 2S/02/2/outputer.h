#pragma once


///Class which is used to print the spiral traversal of matrix
class Outputer
{
public:
  virtual ~Outputer();
  ///Method which prints the spiral traversal of matrix
  virtual void out(int **a, int n) = 0;
  
  ///Method which returns the spiral traversal of matrix
  int *output(int **a, int n);
};