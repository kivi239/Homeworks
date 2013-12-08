#include <cstdio>
#include "char_stack.h"
#include <cstring>
#include <iostream>


using namespace std;
using namespace CharStacks;

bool isOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isNumber(char c)                                                                                      
{
  return ('0' <= c && c <= '9');
}

bool priority(char a, char b)
{
  return (a == '*' || a == '/' || b == '+' || b == '-');
}

void parse(CharStack &s, char c)
{
  if (c == '(')
  {
    push(s, c);
    return;
  }
  if (isOperator(c))
  {
    while (!isEmpty(s) && isOperator(top(s)) && priority(top(s), c))
      printf("%c ", pop(s));
    push(s, c);
    return;
  }
  if (isNumber(c))
  {
    printf("%c ", c);
    return;
  }
  if (c == ')')
  {
    while (s.head->value != '(')
      printf("%c ", pop(s));
    pop(s);
  }
} 

int main()
{
  printf("Please, enter an infix notation\n");
  CharStack s = create();
  char c = getc(stdin);
  while (c != '\n')
  {
    parse(s, c);
    c = getc(stdin);
  }
  
  while (!isEmpty(s))
    printf("%c ", pop(s));
  
  return 0;
}           