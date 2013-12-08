#include <cstdio>
#include "cyclic_list.h"

using namespace CyclicLists;

int main()
{
  printf("Please, enter the number of soldiers and step\n");
  int n = 0;
  int m = 0;
  scanf("%d%d", &n, &m);

  CyclicList l = create(n);
  remove(l, m);
  printTheFirst(l);
  deleteAll(l.head);

  return 0;
}

                                                                    