#include "pointer_stack.h"
#include "array_stack.h"
#include <cstdio>

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

void parse(PointerStack &s, char c, char *prefix, int &l)
{
  if (c == '(')
  {
    s.push((int)c);
    return;
  }
  if (isOperator(c))
  {
    while (!s.isEmpty() && isOperator(s.top()) && priority(s.top(), c))                                       
    {
      prefix[l++] = s.pop();
      prefix[l++] = ' ';
    } 
    s.push(c);
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
    while (s.top() != '(')
    {
      prefix[l++] = s.pop();
      prefix[l++] = ' ';
    }
    s.pop();
  }
} 

void transformToPrefix(char *prefix, int &l)
{
  PointerStack s;
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
  
  while (!s.isEmpty())
  {
    prefix[l++] = s.pop();
    prefix[l++] = ' ';
  }
  
}

int calc(int a, int b, char c)
{
  if (c == '+')
    return a + b;
  if (c == '*')
    return a * b;
  if (c == '-')
    return a - b;
  return a / b;
}                                                                

void transformToInt(char *prefix, int l)
{
  ArrayStack s;
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
      double b = s.pop();                                                                              
      double a = s.pop();
      s.push(calc(a, b, c));
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
      s.push(number);
    }         
  }
  printf("%d\n", s.pop());
}

int main()
{
  printf("Please, enter the infix notation\n");
  char *prefix = new char[1000];
  int len = 0;
  transformToPrefix(prefix, len);
  transformToInt(prefix, len);
  delete[] prefix;

  return 0;
}
