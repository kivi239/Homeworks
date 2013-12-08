#include <cstdio>
#include <iostream>

using namespace std;

const int alph = (int)'z';

bool endOfWord(char c)
{
  return (c > 'z' || c < 'a') && (c < 'A' || c > 'Z');
}                                                                                                               

int main()
{
  freopen("file.txt", "r", stdin);
  bool wasSymbol[alph];
  for (int i = 0; i < alph; i++)
    wasSymbol[i] = false;
  char c;
  while (scanf("%c", &c) > 0)
  {
    if (endOfWord(c))
    {
      for (int i = 0; i < alph; i++)
        wasSymbol[i] = false;
      printf("\n");
    }
    else
    {
      if (!wasSymbol[(int)c])
        printf("%c", c);
      wasSymbol[(int)c] = true;
    }
  }

  return 0;
}