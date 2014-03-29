#include "sort.h"
#include <algorithm>

Sort::~Sort() {}

void swap(int *&a, int *&b)
{
  int *tmp = a;
  a = b;
  b = tmp;
}

void Sort::sort(int **a, int l, int r)
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
    this->sort(a, l, j);
  if (i < r)
    this->sort(a, i, r);
}