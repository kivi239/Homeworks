#include <cstdio>

const int maxSize = 100500;

void sieve(int* a, int n)
{
  for (int i = 2; i <= n; i++)
    if (a[i] && (long long)i * i <= n)
      for (int j = i * 2; j <= n; j += i)
        a[j] = false;
} 

int main()
{
  printf("Please, enter an integer number\n");
  int n = 0;
  scanf("%d", &n);
 
  int isPrime[maxSize];
  for (int i = 2; i <= maxSize; i++)
    isPrime[i] = true;

  sieve(isPrime, n);
  
  for (int i = 2; i <= n; i++)
    if (isPrime[i])
      printf("%d\n", i);

  return 0;
}