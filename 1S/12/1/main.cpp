#include <cstdio>
#include <cstring>

const int maxLen = 100500;

bool isDigit(char c)
{
  return ('0' <= c && c <= '9');
}

bool ruleT(int &, char *);
bool ruleE_(int &, char *);
bool ruleF(int &, char *);
bool ruleT_(int &, char *);
bool isCorrectNumber(int &, char *);
bool ruleE(int &, char *);

bool isCorrect(int &pos, char *str)
{
  return (ruleE(pos, str) && str[pos] == '\0');
}

bool ruleE(int &pos, char *str)
{
  return (ruleT(pos, str) && ruleE_(pos, str));                                              
}

bool ruleE_(int &pos, char *str)
{
  if (str[pos] != '+' && str[pos] != '-')
    return true;
  pos++;
  return (ruleT(pos, str) && ruleE_(pos, str));
}

bool ruleT(int &pos, char *str)
{
  return (ruleF(pos, str) && ruleT_(pos, str));
}

bool ruleT_(int &pos, char *str)
{
  if (str[pos] != '*' && str[pos] != '/')
    return true;
  pos++;
  return (ruleF(pos, str) && ruleT_(pos, str));
}

bool ruleF(int &pos, char *str)
{
  if (str[pos] == '(')
  {
    pos++;
    bool answer = ruleE(pos, str);
    if (str[pos] != ')')
      return false;
    pos++;
    return answer;
  }
  return isCorrectNumber(pos, str);
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

bool isCorrectNumber(int &pos, char *number)
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
      else if (cur == 'E')
        state = startExpCode;
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
