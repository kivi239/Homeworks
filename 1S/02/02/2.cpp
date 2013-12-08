#include <stdio.h>

int sqr(int x)
{
  return x * x;
}

int power(int a, int n)
{
  if (n == 0)
    return 1;
  if (n % 2 == 0)
    return sqr(power(a, n / 2));
  else
    return power(a, n - 1) * a;
}

int main()
{
  printf("Please, enter two integer numbers\n");
  int a = 0;
  int n = 0;
  scanf("%d%d", &a, &n);
  printf("%d\n", power(a, n));

  return 0;
}