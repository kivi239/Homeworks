#include <cstdio>

int fib(int n)
{
  if (n == 0 || n == 1)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

int main()
{
  printf("Please, enter an integer number\n");
  int n;     
  scanf("%d", &n);

  printf("%d\n", fib(n));

  return 0;
}