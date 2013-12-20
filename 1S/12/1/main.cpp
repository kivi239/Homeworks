#include <cstdio>
#include <cstring>

const int maxLen = 100500;

bool isDigit(char c)
{
  return ('0' <= c && c <= '9');
}

bool T(int &, char *);
bool E_(int &, char *);
bool F(int &, char *);
bool T_(int &, char *);
bool id(int &, char *);
bool E(int &, char *);

bool isCorrect(int &pos, char *str)
{
  return (E(pos, str) && str[pos] == '\0');
}

bool E(int &pos, char *str)
{
  return (T(pos, str) && E_(pos, str));                                              
}

bool E_(int &pos, char *str)
{
  if (str[pos] != '+' && str[pos] != '-')
    return true;
  pos++;
  return (T(pos, str) && E_(pos, str));
}

bool T(int &pos, char *str)
{
  return (F(pos, str) && T_(pos, str));
}

bool T_(int &pos, char *str)
{
  if (str[pos] != '*' && str[pos] != '/')
    return true;
  pos++;
  return (F(pos, str) && T_(pos, str));
}

bool F(int &pos, char *str)
{
  if (str[pos] == '(')
  {
    pos++;
    bool answer = E(pos, str);
    if (str[pos] != ')')
      return false;
    pos++;
    return answer;
  }
  return id(pos, str);
}

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

bool id(int &pos, char *number)
{
  int state = startCode;
  while (number[pos] != '\0')
  {
    char cur = number[pos];
    if (state == startCode)
    {
      if (isDigit(cur))
        state = numberCode;
      else if (cur == '-')
        state = numberSignCode;
      else 
        break;
    }
    else if (state == numberSignCode)
    {
      if (isDigit(cur))
        state = numberCode;
      else
        break;
    }
    else if (state == numberCode)
    {
      if (cur == '.')
        state = startFracPartCode;
      else if (!isDigit(cur))
        break;                                                         
    }
    else if (state == startFracPartCode)
    {
      if (isDigit(cur))                                                                                         
        state = fracPartCode;
      else
        break;
    }
    else if (state == fracPartCode)
    {
      if (cur == 'E')
        state = startExpCode;                                                                   
      else if (!isDigit(cur))
        break;
    }
    else if (state == startExpCode)
    {
      if (isDigit(cur))
        state = expCode;
      else if (cur == '+' || cur == '-')
        state = expSignCode;
      else 
        break;
    }
    else if (state == expSignCode)
    {
      if (isDigit(cur))
        state = expCode;
      else
        break;
    }
    else if (state == expCode)
    {
      if (!isDigit(cur))
        break;
    }
    pos++;
  }

  return (state == numberCode || state == fracPartCode || state == expCode);
}

int main()
{
  puts("Please, enter an expression");

  char s[maxLen];
  for (int i = 0; i < maxLen; i++)
    s[i] = '\0';
  gets(s);

  int pos = 0;
  if (isCorrect(pos, s))
    printf("It is a correct expression\n");
  else
    printf("It is not a correct expression\n");

  return 0;
}
