#include <cstdio>
#include "double_stack.h"
#include "char_stack.h"
#include <iostream>

using namespace std;
using namespace CharStacks;
using namespace DoubleStacks;

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

void parse(CharStack &s, char c, char *prefix, int &l)
{
  if (c == '(')
  {
    push(s, c);
    return;
  }
  if (isOperator(c))
  {
    while (!isEmpty(s) && isOperator(top(s)) && priority(top(s), c))
    {
      prefix[l++] = pop(s);
      prefix[l++] = ' ';
    } 
    push(s, c);
    return;
  }
  if (isNumber(c))
  {
    prefix[l++] = c;
    prefix[l++] = ' ';
    return;
  }
  if (c == ')')
  {
    while (s.head->value != '(')
    {
      prefix[l++] = pop(s);
      prefix[l++] = ' ';
    }
    pop(s);
  }
} 

void transformToPrefix(char *prefix, int &l)
{
  CharStack s = CharStacks::create();
  char c = getc(stdin);
  while (c != '\n')
  {
    if (c == ' ')
    {
      c = getc(stdin);
      continue;
    }
    parse(s, c, prefix, l);
    c = getc(stdin);
  }
  
  while (!isEmpty(s))
  {
    prefix[l++] = pop(s);
    prefix[l++] = ' ';
  }
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

void transformToDouble(char *prefix, int l)
{
  DoubleStack s = DoubleStacks::create();
  int id = 0;
  while (id < l)
  {               
    char c = prefix[id];
    if (c == ' ')
    {
      id++;
      continue;
    }
    if (isOperator(c))
    {
      double b = pop(s);                                                                              
      double a = pop(s);
      push(s, calc(a, b, c));
      id++;
    }
    else
    {
      int number = 0;
      c = prefix[id];
      while (isNumber(c))
      {
        number *= 10;
        number += (c - '0');
        id++;
        c = prefix[id];
      }
      push(s, double(number));
    }         
  }
  printf("%.6lf\n", pop(s));
}

int main()
{
  printf("Please, enter the infix notation\n");
  char *prefix = new char[1000];
  int len = 0;
  transformToPrefix(prefix, len);
  transformToDouble(prefix, len);
  delete[] prefix;

  return 0;
}
