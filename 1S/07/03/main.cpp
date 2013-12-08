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
  freopen("bigtext.txt", "r", stdin);
  char s[maxLen];
  char t[maxLen];
  for (int i = 0; i < maxLen; i++)
  {
    s[i] = '\0';
    t[i] = '\0';
  }
  HashTable table = HashTables::create(10);
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
      String str = create(t, curLen);
      add(table, str, 1);

      remove(str);
    
      if (loadFactor(table) > 5)
        table = makeBigger(table);
    }
  }
             
  printf("Size of hash table is %d\n", table.size);
  printf("Amount of elements is %d\n", table.occupied);
  printf("Load factor is %.4lf\n", loadFactor(table));
  printf("Mean length of lists is %.4lf\n", meanLength(table));
  List maxList = maxLength(table);
  printf("Maximum length of lists is %d\n", Lists::size(maxList));
  puts("Maximum list contains strings");
  print(maxList);
  printf("Amount of empty cells is %d\n", empty(table));
    
  deleteAll(table);
                         
  return 0;
}             