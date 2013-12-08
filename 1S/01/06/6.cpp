#include <cstdio>
#include <cstring>

const int maxSize = 100500;

int kmp(char* s, int* p, int n)
{
  int l = strlen(s);

  for (int i = 1; i < l; i++)
  {
    int cur = p[i - 1];
    while (cur > 0 && s[i] != s[cur])
      cur = p[cur - 1];
    if (s[i] == s[cur])
      p[i] = cur + 1;
    else
      p[i] = 0;
  }

  int cnt = 0;
  for (int i = n; i < l; i++)
    cnt += (p[i] == n);

  return cnt;
}

int main()
{
  printf("Please, enter two strings\n");
  char s[maxSize];
  char t[maxSize];
  scanf("%s", t);
  scanf("%s", s);

  int n = strlen(t);
  int m = strlen(s);

  t[n] = '#';
  for (int i = 0; i < m; i++)
    t[i + n + 1] = s[i];

  int p[2 * maxSize + 1];
  for (int i = 0; i < 2 * maxSize + 1; i++)
    p[i] = 0;

  printf("%d\n", kmp(t, p, n));

  return 0;
}