#include <cstdio>
#include "sortTest.h"
#include "outputer.h"

int main()
{
  SortTest sortTest;
  QTest::qExec(&sortTest);

  printf("Please, enter n and m\n");
  int n = 0;
  int m = 0;
  scanf("%d%d", &n, &m);
  printf("Please, enter the matrix of size n * m\n");
  int **a = new int*[m];
  for (int i = 0; i < m; i++)
    a[i] = new int[n];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &a[j][i]);

  Sort s;
  s.sort(a, 0, m - 1);

  Outputer output;
  output.out(a, n, m);

  for (int i = 0; i < m; i++)
    delete[] a[i];
  delete[] a;

  return 0;
}
