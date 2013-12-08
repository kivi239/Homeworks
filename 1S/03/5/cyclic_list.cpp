#include <cstdio>
#include "cyclic_list.h"
#include <iostream>

using namespace std;
                                             
using namespace CyclicLists;

CyclicList CyclicLists::create(int n)
{
  CyclicList l = {NULL};
  l.head = new CyclicListElement;
  l.head->next = NULL;
  CyclicListElement *tmp = l.head;

  for (int i = 1; i <= n; i++)
  {
    CyclicListElement *newElement = new CyclicListElement;
    newElement->value = i;
    newElement->next = NULL;
    tmp->next = newElement;
    tmp = newElement;
  }
  tmp->next = l.head->next;

  return l;  
}
                                                                                                              
bool CyclicLists::isOneElement(CyclicList &l)
{
  return (l.head != NULL) && (l.head->next == l.head->next->next);
}

int CyclicLists::size(CyclicList &l)
{
  if (l.head->next == NULL)
    return 0;
  CyclicListElement *curElement = l.head->next;
  int cnt = 0;
  while (curElement->next != l.head->next)
  {
    cnt++;
    curElement = curElement->next;
  }
  return cnt + 1;
}

void CyclicLists::remove(CyclicList &l, int number)
{
  CyclicListElement *curElement = l.head;
  int step = number;
  if (step == 1)
    step += size(l);
  while (!isOneElement(l))
  {
    for (int i = 1; i < step; i++)
      curElement = curElement->next;
    step = number;
    CyclicListElement *tmpElement = curElement->next;
    curElement->next = curElement->next->next;
    
    if (l.head->next == tmpElement)
      l.head->next = curElement->next;
    
    delete tmpElement;
  }
}

void CyclicLists::printTheFirst(CyclicList &l)
{
  if (l.head->next != NULL)
    printf("%d\n", l.head->next->value);
}

void CyclicLists::deleteAll(CyclicListElement *curElement)
{
  if (curElement != curElement->next)
  {
    deleteAll(curElement->next);
    //delete curElement;
  }
  delete curElement;                                                      
}

