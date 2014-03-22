#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

void out(int **a, int n, int m)
{
  for (int i = 0; i < n; i++, printf("\n"))
    for (int j = 0; j < m; j++)
      printf("%d ", a[j][i]);
}

void quickSort(int **a, int l, int r)
{
  int i = l;
  int j = r;
  int m = rand() % (r - l + 1) + l;

  while (i <= j) 
  {
    while ( a[i][0] < a[m][0]) 
      i++;
    while ( a[j][0] > a[m][0]) 
      j--;

    if (i <= j) 
    {
      swap(a[i], a[j]);
      i++; 
      j--;
    }
  } 

  if (l < j)
    quickSort(a, l, j);
  if (i < r)
    quickSort(a, i, r);
}

int main()
{
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
  
  quickSort(a, 0, m - 1);
  
  out(a, n, m);

  for (int i = 0; i < m; i++)
    delete[] a[i];
  delete[] a;
  
  return 0;
}