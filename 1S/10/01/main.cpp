#include <cstdio>
#include "priority_queue.h"

using namespace PriorityQueues;

const int sizeOfAlphabet = 128;

void print(long long x)
{
  char answer[20];
  for (int i = 0; i < 20; i++)
    answer[i] = '\0';
  int len = 0;
  while (x > 0)
  {
    answer[len++] = (x % 3 - 1) + '0';
    x /= 3;
  }
  for (int i = 0; i < len; i++)
    printf("%c", answer[len - i - 1]);
  printf(" ");
}

int main()
{
  PriorityQueue q = create();
  freopen("file.txt", "r", stdin);
  freopen("archive.txt", "w", stdout);

  int amount[sizeOfAlphabet];
  long long code[sizeOfAlphabet];
  for (int i = 0; i < sizeOfAlphabet; i++)
  {
    amount[i] = 0;
    code[i] = 0;
  }

  char c = '\0';
  while (scanf("%c", &c) > 0)                                                                            
    amount[(int)c]++;

  for (int addedChar = 0; addedChar < sizeOfAlphabet; addedChar++)
    if (amount[addedChar] > 0)
      add(q, amount[addedChar], (char)addedChar);
  
  while (size(q) > 1)
    merge(q);

  if (size(q) == 1)
    traversal(q, code);
  freopen("file.txt", "r", stdin);
  
  out(q);
  puts("");

  while (scanf("%c", &c) > 0)
    print(code[(int)c]);

  remove(q);

  return 0;
}