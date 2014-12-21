#include <cstdio>
#include <cstring>

#include <iostream>
using namespace std;

enum States
{
  startCode,
  numberCode,
  numberSignCode,
  startFracPartCode,
  fracPartCode,
  startExpCode,
  expCode,
  expSignCode,
  errorCode,
};

const int maxLen = 1050;

bool isDigit(char c)
{
  return ('0' <= c && c <= '9');
}

bool isCorrect(char *number, int length)
{
  int state = startCode;
  for (int i = 0; i < length; i++)                                                                                                 
  {
    char cur = number[i];
    cerr << state << endl;
    if (state == startCode)
    {
      if (isDigit(cur))
        state = numberCode;
      else if (cur == '-')
        state = numberSignCode;
      else 
        state = errorCode;
    }
    else if (state == numberSignCode)
    {
      if (isDigit(cur))
        state = numberCode;
      else
        state = errorCode;
    }
    else if (state == numberCode)
    {
      if (cur == '.')
        state = startFracPartCode;
      else if (!isDigit(cur))
        state = errorCode;                                                         
    }
    else if (state == startFracPartCode)
    {
      if (isDigit(cur))                                                                                         
        state = fracPartCode;
      else
        state = errorCode;
    }
    else if (state == fracPartCode)
    {
      if (cur == 'E')
        state = startExpCode;
      else if (!isDigit(cur))
        state = errorCode;
    }
    else if (state == startExpCode)
    {
      if (isDigit(cur))
        state = expCode;
      else if (cur == '+' || cur == '-')
        state = expSignCode;
      else 
        state = errorCode;
    }
    else if (state == expSignCode)
    {
      if (isDigit(cur))
        state = expCode;
      else
        state = errorCode;
    }
    else if (state == expCode)
    {
      if (!isDigit(cur))
        state = errorCode;
    }
  }
  
  return (state == numberCode || state == fracPartCode || state == expCode);
}

int main()
{
  printf("Please, enter a floating-point number\n");
  char *number = new char[maxLen];
  scanf("%s", number);

  if (isCorrect(number, strlen(number)))
    printf("It is a correct notation\n");
  else 
    printf("It is an incorrect notation\n");

  delete[] number;

  return 0;
}