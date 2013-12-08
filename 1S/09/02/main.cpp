#include <cstdio>
#include <cstring>
#include "String.h"

using namespace Strings;

typedef unsigned long long ull;

const int lengthOfChar = 1;
const ull P = 317;

void readString(String &str)
{
  char s[1] = {'\0'};
  scanf("%c", &s[0]);
  while (s[0] != '\n')
  {
    String newStr = create(s, 1);
    concatenation(newStr, str);
    remove(newStr);

    scanf("%c", &s[0]);                                                                                                        
  }
}

int RabinKarp(char *text, int lengthOfText, char *substr, int lengthOfSubstr)
{
  if (lengthOfSubstr > lengthOfText)
    return 0;

  ull hashOfSubstr = 0;
  for (int i = 0; i < lengthOfSubstr; i++)
  {
    hashOfSubstr *= P;
    hashOfSubstr += int(substr[i]);
  }
  
  ull curHash = 0;
  for (int i = 0; i < lengthOfSubstr; i++)
  {
    curHash *= P;
    curHash += (ull)text[i];
  }                                                              

  ull power = 1;
  for (int i = 0; i < lengthOfSubstr; i++)
    power *= P;

  int answer = (curHash == hashOfSubstr);
  for (int i = 1; i < lengthOfText - lengthOfSubstr + 1; i++)
  {
    curHash *= P;
    curHash -= (ull)text[i - 1] * power;
    curHash += (ull)text[i + lengthOfSubstr - 1];
    answer += (curHash == hashOfSubstr);
  }
                     
  return answer;
}

int main()
{
  freopen("strings2.txt", "r", stdin);

  char s[1] = {'\0'};
  
  String str = create(s, 0);
  readString(str);
  int lenOfText = length(str);
  char *text = convertToChar(str);
  remove(str);
  
  str = create(s, 0);
  readString(str);
  int lenOfSubstr = length(str);
  char *substr = convertToChar(str);
  remove(str);

  printf("The text contains the substring %d time(s)\n", RabinKarp(text, lenOfText, substr, lenOfSubstr));

  delete[] text;
  delete[] substr;

  return 0;
}
