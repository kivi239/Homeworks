#include <stdio.h>

const int N = 100500;

void swap(int& a, int& b)
{                                       
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

int main()
{
  printf("Please, enter n and m\n");
  int n = 0;
  int m = 0;
  scanf("%d%d", &n, &m);
  printf("Please, enter the array of size n + m\n");
  int a[N];
  
  for (int i = 0; i < N; i++)
    a[i] = 0;
  
  for (int i = 0; i < n + m; i++)
    scanf("%d", &a[i]);

  for (int i = 0; i < n / 2; i++)
    swap(a[i], a[n - i - 1]);
  
  for (int i = n; i < n + m / 2; i++)
    swap(a[i], a[2 * n + m - i - 1]);
  
  for (int i = 0; i < (n + m) / 2; i++)
    swap(a[i], a[n + m - i - 1]);

  for (int i = 0; i < n + m; i++)
    printf("%d ", a[i]);

  return 0;
} 