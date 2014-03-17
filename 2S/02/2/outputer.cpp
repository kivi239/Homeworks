#include "outputer.h"

Outputer::~Outputer() {}

int * Outputer::output(int **a, int n)
{
  int *arr = new int[n * n];
  int size = 0;
  int x = n / 2;
  int y = n / 2;
  int step = 1;

  for (int i = 0; i < n / 2; i++)
  {
    for (int j = 0; j < step; j++)
    {
      arr[size++] = a[x][y];
      x--;
    }
    for (int j = 0; j < step; j++)
    {
      arr[size++] = a[x][y];
      y++;
    }
    for (int j = 0; j < step + 1; j++)
    {
      arr[size++] = a[x][y];
      x++;
    }
    for (int j = 0; j < step + 1; j++)
    {
      arr[size++] = a[x][y];
      y--;
    }
    step += 2;
  }
  for (int i = n - 1; i >= 0; i--)
    arr[size++] = a[i][0];

  return arr;
}
