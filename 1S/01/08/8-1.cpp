#include <stdio.h>

int main()
{
  int n = 0;
  printf("Please, enter an integer number\n");
  scanf("%d", &n);

  int ans = 1;
  for (int i = 2; i <= n; i++)
    ans *= i;
  
  printf("%d\n", ans);

  return 0;
}