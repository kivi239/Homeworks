#include <stdio.h>

const int maxSum = 28, maxDig = 10;

int main()
{
  int cnt[maxSum];
  for (int i = 0; i < maxSum; i++)
    cnt[i] = 0;
  
  for (int i = 0; i < maxDig; i++)
    for (int j = 0; j < maxDig; j++)
      for (int k = 0; k < maxDig; k++)
        cnt[i + j + k]++;
  
  int ans = 0;
  for (int i = 0; i < maxSum; i++)
    ans += cnt[i] * cnt[i];
  
  printf("%d\n", ans);
  
  return 0;
}