#include <cstdio>
#include "double_stack.h"
#include <iostream>

using namespace std;

using namespace DoubleStacks;

bool isNumber(char c)
{
  return ('0' <= c && c <= '9');
}

bool isOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

double calc(double a, double b, char c)
{
  if (c == '+')
    return a + b;
  if (c == '*')
    return a * b;
  if (c == '-')
    return a - b;
  return a / b;
}

int main()
{
  printf("Please, enter the postfix notation\n");
  
  char c;
  scanf("%c", &c);
  DoubleStack s = create();
  while (c != '\n')
  {               
    if (c == ' ')
    {  
      scanf("%c", &c);
      continue;
    }
    if (isOperator(c))
    {
      double b = pop(s);
      double a = pop(s);
      push(s, calc(a, b, c));
      scanf("%c", &c);
    }
    else
    {
      int number = 0;
      while (isNumber(c))
      {
        number *= 10;
        number += (c - '0');
        scanf("%c", &c);
      }
      push(s, double(number));
    }
  }

  printf("%.6lf\n", pop(s));

  return 0;
}