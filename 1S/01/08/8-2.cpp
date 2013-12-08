#include <stdio.h>

int fact(int n)
{
  if (n == 1)
    return 1;
  return n * fact(n - 1);
}

int main()
{
  int n = 0;
  printf("Please, enter an integer number\n");
  scanf("%d", &n);
  printf("%d\n", fact(n));

  return 0;
}