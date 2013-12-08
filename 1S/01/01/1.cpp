#include <stdio.h>

int main()
{
  printf("Please, enter the number\n");
  int x = 0;
  scanf("%d", &x);
  int sqr = x * x;
  printf("%d\n", (sqr + x) * (sqr + 1));

  return 0;
}