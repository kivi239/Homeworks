#include "console_outputer.h"
#include <cstdio>

ConsoleOutputer::~ConsoleOutputer() {}

void ConsoleOutputer::out(int **a, int n)
{
  int x = n / 2;
  int y = n / 2;
  int step = 1;

  for (int i = 0; i < n / 2; i++)
  {
    for (int j = 0; j < step; j++)
    {
      printf("%d ", a[x][y]);
      x--;
    }
    for (int j = 0; j < step; j++)
    {
      printf("%d ", a[x][y]);
      y++;
    }
    for (int j = 0; j < step + 1; j++)
    {
      printf("%d ", a[x][y]);
      x++;
    }
    for (int j = 0; j < step + 1; j++)
    {
      printf("%d ", a[x][y]);
      y--;
    }
    step += 2;
  }
  for (int i = n - 1; i >= 0; i--)
    printf("%d ", a[i][0]);
}   