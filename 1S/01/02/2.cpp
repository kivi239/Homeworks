#include <cstdio>

int division(int a, int b)
{
  int k = 0;
  int sum = 0;
  int sign = 1;

  if ((a >= 0 && b < 0) || (a < 0 && b >= 0))
  {
    sign = -1;
    b = -b;
  }

  if (a >= 0)
    while (sum + b <= a)
    {
      sum += b;
      k++;
    }
  else
    while (sum > a)
    {
       sum += b;
       k++;
    }

  return k * sign;
}

int main()
{
  printf("Please, enter two integer numbers\n");
  int n = 0;
  int m = 0;
  scanf("%d%d", &n, &m);

  printf("%d\n", division(n, m));

  return 0;
}