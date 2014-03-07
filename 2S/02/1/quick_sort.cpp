#include "quick_sort.h"
#include <cstdio>
#include <ctime>
#include <algorithm>

void swap(int &x, int &y)
{
  if (x == y)
    return;
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
}

QuickSort::QuickSort() {}

QuickSort::~QuickSort() {}

void QuickSort::sort(int *begin, int *end) 
{
  int l = 0;
  int r = end - begin - 1;
  int m = rand() % (r + 1);
  
  while (l <= r)
  {
    while (begin[l] < begin[m])
      l++;
    while (begin[r] > begin[m])
      r--;

    if (l <= r)
    {
      swap(begin[l], begin[r]);
      l++;
      r--;
    }
  }

  if (r > 0)
    this->sort(begin, begin + r + 1);
  if (l < end - begin - 1)
    this->sort(begin + l, end);
}
