#include <cstdio>
#include <cstring>
#include "hash_table.h"
                                                                                
using namespace HashTables;

const int maxLen = 100;

bool suitable(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '-'));
}

int main()
{
  freopen("text1.txt", "r", stdin);
  freopen("result.txt", "w", stdout);
  
  char s[maxLen];
  char t[maxLen];
  for (int i = 0; i < maxLen; i++)
  {
    s[i] = '\0';
    t[i] = '\0';
  }                                                                             
  HashTable table = HashTables::create(2);
  while (scanf("%s", s) > 0)
  {
    int id = 0;
    int length = strlen(s);
    while (id < length)
    {
      int curLen = 0;
      while (id < length && suitable(s[id]))
        t[curLen++] = s[id++];
      id++;
      if (curLen > 1 || (curLen == 1 && t[0] != '-'))
      {
        String str = create(t, curLen);
        add(table, str, 1);
      }
      if (loadFactor(table) > 4)
        table = makeBigger(table);
    }
  }

  freopen("text2.txt", "r", stdin);
  while (scanf("%s", s) > 0)
  {
    int id = 0;                                                                                          
    int length = strlen(s);
    while (id < length)
    {
      int curLen = 0;
      while (suitable(s[id]))
        t[curLen++] = s[id++];
      id++;
      if (curLen > 1 || (curLen == 1 && t[0] != '-'))
      {
        String str = create(t, curLen);
        if (find(table, str))
        {
          print(str);
          puts("");
          remove(table, str);
        }
        remove(str);
      }
     ;
    }
  } 
    
  deleteAll(table);
                         
  return 0;
}             