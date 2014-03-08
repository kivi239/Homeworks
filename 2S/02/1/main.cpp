#include "quick_sort.h"
#include "merge_sort.h"
#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>

const int size = 10;

int main()
{
  srand(time(NULL));

  printf("Please, enter an integer n\n");
  int n = 0;
  scanf("%d", &n);
  
  printf("Please, enter the array of size n\n");
  int *a = new int[n];
  
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  Sort *s = new QuickSort();
  
  printf("Please, enter the method of sorting\n1 - QuickSort\n2 - MergeSort\n");
  int method = 0;
  scanf("%d", &method);

  if (method == 2)
  {
    delete s;
    s = new MergeSort();
  }

  s->sort(a, a + n);
  
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);  

  delete[] a;
  delete s;

  return 0;
}
