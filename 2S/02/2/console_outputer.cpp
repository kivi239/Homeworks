#include "console_outputer.h"
#include <cstdio>

ConsoleOutputer::~ConsoleOutputer() {}

void ConsoleOutputer::out(int **a, int n)
{
  int *arr = output(a, n);
  for (int i = 0; i < n * n; i++)
    printf("%d ", arr[i]);

  delete[] arr;
}   
