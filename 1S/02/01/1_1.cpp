#include <cstdio>

const int maxSize = 100;

int main()
{
  printf("Please, enter an integer number\n");
  int n;
  scanf("%d", &n);

  int f[maxSize];
  for (int i = 2; i < maxSize; i++)
    f[i] = 0;
  f[0] = 1;
  f[1] = 1;

  for (int i = 2; i <= n; i++)
    f[i] = f[i - 1] + f[i - 2];

  printf("%d\n", f[n]);

  return 0;
}