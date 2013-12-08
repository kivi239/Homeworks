#include <cstdio>
#include <cstdlib>
#include <ctime>

const int maxSize = 100500;

void swap(int& x, int& y)
{ 
  if (x == y)
    return;
  
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
}

void quickSort(int* a, int l, int r)
{
  int i = l;                                                                                      
  int j = r;
  int m = rand() % (r - l + 1) + l;

  while (i <= j) 
  {
    while ( a[i] < a[m]) 
      i++;
    while ( a[j] > a[m]) 
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
  srand(time(NULL));

  printf("Please, enter an integer n\n");
  int n = 0;
  scanf("%d", &n);
  printf("Please, enter the array of size n\n");
  
  int *a = new int[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  quickSort(a, 0, n - 1);

  int maxElement = -1;
  for (int i = n - 1; i > 0; i--)
    if (a[i] == a[i - 1])
    {
      maxElement = a[i];
      break;
    }
  if (maxElement == -1)
    printf("Each element is unique\n");
  else
    printf("Maximal non-unique element is %d\n", maxElement);

  delete[] a;

  return 0;
}      