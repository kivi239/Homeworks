#include <cstdio>
#include <cstring>

const int maxSize = 100500;

char pair(char c)
{
  if (c == '}')
    return '{';
  if (c == ']')
    return '[';
  return '(';
}

int main()                                                                                     
{
  printf("Please, enter the bracket sequence\n");
  char s[maxSize];
  for (int i = 0; i < maxSize; i++)
    s[i] = ' ';
  
  scanf("%s", s);
  
  int l = strlen(s);
  int bal = 0;
  bool isReg = true;
  char stack[maxSize];
  
  for (int i = 0; i < maxSize; i++)
    stack[i] = ' ';

  for (int i = 0; i < l; i++)
  {
    if (s[i] == '[' || s[i] == '{' || s[i] == '(')
      stack[bal++] = s[i];
    else
    {
      if (bal == 0)
        isReg = false;
      else
      {
        if (stack[bal - 1] == pair(s[i]))
          bal--;
        else
          isReg = false;
      }
    }
  }
  
  isReg &= (bal == 0);

  if (isReg)
    printf("It is a regular bracket sequence\n");
  else
    printf("It is not a regular bracket sequence\n");

  return 0;
}