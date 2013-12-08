#include <cstdio>
#include <cstring>

const int maxLog = 10;
const int maxSize = 100500;

void swap(char& a, char& b)
{
  if (a == b)
    return;

  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

int intToStr(int x, char* tmp)
{
  int k = 0;
  while (x > 0)
  {
    tmp[k++] = char((x % 10) + '0');
    x /= 10;
  }

  for (int i = 0; i < k / 2; i++)
    swap(tmp[i], tmp[k - i - 1]);
  return k;
}

void out(char* s, int l)
{
  for (int i = 0; i < l; i++)
    printf("%c", s[i]);
}

void repres(int n, int prev, char* s, int l)
{
  for (int i = prev; i < n; i++)
  {
    if (n - i < i)
      break;
    char tmp[maxLog];
    int l1 = intToStr(i, tmp);
    
    int add = 0;
    if (l != 0)
    {
      s[l] = '+';
      add = 1;
    }
    for (int j = 0; j < l1; j++)
      s[l + j + add] = tmp[j];

    repres(n - i, i, s, l + l1 + add);
  }
  int add = 0;
  if (l != 0)
  {
    s[l] = '+';
    add = 1;
  }
  char tmp[maxLog];
  int l1 = intToStr(n, tmp);
  out(s, l + add);
  out(tmp, l1);
  printf("\n");
}

int main()
{
  printf("Please, enter an integer number\n");
  int n;
  scanf("%d", &n);

  char s[maxSize];

  repres(n, 1, s, 0);

  return 0;
}    