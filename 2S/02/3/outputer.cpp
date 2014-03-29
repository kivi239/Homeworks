#include <cstdio>
#include "outputer.h"

Outputer::~Outputer() {}

void Outputer::out(int **a, int n, int m)
{
  for (int i = 0; i < n; i++, printf("\n"))
   for (int j = 0; j < m; j++)
     printf("%d ", a[j][i]);
}