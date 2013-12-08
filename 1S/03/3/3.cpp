#include <cstdio>

const int digits = 10;

int main()
{
  printf("Please, enter an integer number\n");
  int n;
  scanf("%d", &n);

  int cnt[digits];
  for (int i = 0; i < digits; i++)
    cnt[i] = 0;

  while (n > 0)
  {
    cnt[n % 10]++;
    n /= 10;
  }

  int mindigit = -1;
  for (int i = digits - 1; i > 0; i--)
    if (cnt[i] > 0)
      mindigit = i;

  printf("%d", mindigit);
  cnt[mindigit]--;
  for (int curDig = 0; curDig < digits; curDig++)
    for (int j = 0; j < cnt[curDig]; j++)
      printf("%d", curDig);
                                                                                                     
  return 0;
}
