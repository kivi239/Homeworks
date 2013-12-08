#include <cstdio>
#include "String.h"

using namespace Strings;

const int P = 337;

Char *createChar(char c)
{
  Char *newChar = new Char;
  newChar->symbol = c;
  newChar->next = NULL;

  return newChar;
}

String Strings::create(char *str, int len)
{
  Char *newChar = createChar('\0');
  String newString = {newChar, newChar};

  for (int i = 0; i < len; i++)
  {
    Char *newChar = createChar(str[i]);
    newString.end->next = newChar;
    newString.end = newChar;
  }

  return newString;                                                                                                       
}

void remove(Char *curChar)
{
  if (curChar == NULL)
    return;

  remove(curChar->next);
  delete curChar;
}

void Strings::remove(String &str)
{
  ::remove(str.begin);
}

String Strings::clone(String &str)
{
  String newString = create(NULL, 0);
  Char *curChar = str.begin->next;

  while (curChar != NULL)
  {
    Char *newChar = createChar(curChar->symbol);
    newString.end->next = newChar;
    newString.end = newChar;
  
    curChar = curChar->next;
  } 

  return newString;
}                                                           

void Strings::concatenation(String &from, String &to)
{                                                                                                                                  
  Char *curChar = from.begin->next;
  while (curChar != NULL)
  {
    Char *newChar = createChar(curChar->symbol);
    to.end->next = newChar;
    to.end = newChar;
    
    curChar = curChar->next;                              
  }
}
                  
bool Strings::areEqual(String &str1, String &str2)
{
  if (length(str1) != length(str2))
    return false;

  Char *curChar1 = str1.begin;
  Char *curChar2 = str2.begin;                               

  while (curChar1 != NULL && curChar2 != NULL)
    if (curChar1->symbol != curChar2->symbol)
      return false;
    else
    {
      curChar1 = curChar1->next;
      curChar2 = curChar2->next;
    }

  return true;
}                                                                               

int Strings::length(String &str)
{
  int len = 0;
  Char *curChar = str.begin->next;

  while (curChar != NULL)
  {
    len++;
    curChar = curChar->next;
  }

  return len;
}

bool Strings::isEmpty(String &str)
{                                                                               
  return (str.begin->next == NULL);
}

String Strings::substr(String &str, int begin, int end)
{
  String newString = create(NULL, 0);

  int curId = 0;
  Char *curChar = str.begin->next;
  while (curChar != NULL && curId < begin)
  {
    curChar = curChar->next;
    curId++;
  }

  while (curChar != NULL && curId <= end)
  {
    Char *newChar = createChar(curChar->symbol);
    newString.end->next = newChar;
    newString.end = newChar;
    
    curId++;
    curChar = curChar->next;
  }           
                 
  return newString;
}

char *Strings::convertToChar(String &str)
{
  int len = length(str);
  char *newStr = new char[len + 1];
  Char *curChar = str.begin->next;

  for (int i = 0; i < len; i++)
  {
    newStr[i] = curChar->symbol;
    curChar = curChar->next;
  }
  newStr[len] = '\0';

  return newStr;
}

void print(Char *curChar)
{
  if (curChar == NULL)
    return; 

  printf("%c", curChar->symbol);
  print(curChar->next);

}

void Strings::print(String &str)
{
  ::print(str.begin->next);
}

int Strings::hashValue(String &str, int mod)
{
  Char *curChar = str.begin->next;
  int hash = 0;
  while (curChar != NULL)
  {
    hash *= P;
    hash += (int)curChar->symbol;
    hash %= mod;
    curChar = curChar->next;
  }

  return hash;
}
                  