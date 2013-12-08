#include <stdio.h>
#include <string.h>

const int maxSize = 100500;

int main()
{
  printf("Please, enter the string\n");
  char s[maxSize];
  for (int i = 0; i < maxSize; i++)
    s[i] = ' ';
  
  scanf("%s", s);

  bool isPal = true;
  int l = strlen(s);
  
  for (int i = 0; i < l / 2; i++)
    isPal &= (s[i] == s[l - i - 1]);
  
  if (isPal)
    printf("It is a palindrome\n");
  else
    printf("It is not a palindrome\n");

  return 0;
}

