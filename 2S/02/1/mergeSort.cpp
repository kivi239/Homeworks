#include "mergeSort.h"
#include <cstdio>

MergeSort::~MergeSort() {}

void MergeSort::sort(int *begin, int *end)
{
  if (end - begin == 1)
    return;

  int m = (end - begin) / 2;

  this->sort(begin, begin + m);
  this->sort(begin + m, end);

  int *arr = new int[end - begin];
  for (int i = 0; i < end - begin; i++)
    arr[i] = 0;
  int size = 0;
  int l = 0;
  int r = m;
  while (l < m || r < end - begin)
  {
    if (r == end - begin || (l < m && begin[l] < begin[r]))
      arr[size++] = begin[l++];
    else
    if (l == m || (r < end - begin && begin[r] <= begin[l]))
      arr[size++] = begin[r++];
  }

  for (int i = 0; i < end - begin; i++)
    begin[i] = arr[i];

  delete[] arr;
}

