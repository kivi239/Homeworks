#include <cstdio>
#include "polynom.h"

using namespace Polynoms;

Polynom Polynoms::create()
{
  Polynom newP = {NULL};
  return newP;
}

void print(Monom *curMonom)
{
  if (curMonom != NULL)
  {
    print(curMonom->next);
    if (curMonom->next == NULL)
      if (curMonom->degree == 0)
        printf("%d", curMonom->coeff);
      else
        printf("%dx^%d", curMonom->coeff, curMonom->degree);
    else
    {
      if (curMonom->coeff > 0)
      {
        if (curMonom->degree == 0)
          printf(" + %d", curMonom->coeff);
        else
          printf(" + %dx^%d", curMonom->coeff, curMonom->degree);
      }
      if (curMonom->coeff < 0)
      {
        if (curMonom->degree == 0)
          printf(" - %d", -curMonom->coeff);
        else
          printf(" - %dx^%d", -curMonom->coeff, curMonom->degree);
      }                                                                                                                   
    }
  }
}
                                                                                                           
void Polynoms::print(Polynom &p)
{
  Monom *cur = p.first;
  if (cur == NULL)
  {
    printf("0");                                                                                                                     
    return;
  }
  ::print(cur);
}

void Polynoms::add(Polynom &p, int coeff, int degree)
{
  Monom *newM = new Monom;
  newM->coeff = coeff;
  newM->degree = degree;                                                                                                        
  Monom *cur = p.first;
  if (cur == NULL || degree < p.first->degree)
  {                                                                                  
    newM->next = cur;
    p.first = newM;
    return;
  }
  if (degree == p.first->degree)
  {
    p.first->coeff += coeff;
    delete newM;
    return;
  }
  
  while (cur->next != NULL && degree > cur->next->degree)
    cur = cur->next;
  
  if (cur->next == NULL || cur->next->degree > degree)
  {
    newM->next = cur->next;
    cur->next = newM;
  }
  else
  {
    cur->next->coeff += coeff;
    delete newM;
  }
}

void Polynoms::add(Polynom &p, Polynom &q, Polynom &r)
{
  Monom *cur = p.first;
  while (cur != NULL)
  {
    add(r, cur->coeff, cur->degree);
    cur = cur->next;
  }
  cur = q.first;
  while (cur != NULL)
  {
    add(r, cur->coeff, cur->degree);
    cur = cur->next;
  }
}
                                                                           
int Polynoms::value(Polynom &p, int x)                                                                                         
{
  Monom *cur = p.first;
  int power = 1;
  int answer = 0;
  while (cur != NULL)
  {
    answer += cur->coeff * power;
    power *= x;
    cur = cur->next;
  }
  return answer;
}

bool Polynoms::areEqual(Polynom &p, Polynom &q)
{
  Monom *curP = p.first;
  Monom *curQ = q.first;

  int coeffP = 0;
  int coeffQ = 0;

  while (curP != NULL || curQ != NULL)
  {
    coeffP = 0;
    coeffQ = 0;
    if (curP != NULL)
    {
      coeffP = curP->coeff;
      curP = curP->next;
    }
    if (curQ != NULL)
    {
      coeffQ = curQ->coeff;
      curQ = curQ->next;
    }
    if (coeffQ != coeffP)
      return false;
  }

  return true;
}

void remove(Monom *curMonom)
{
  if (curMonom != NULL)
  {
    remove(curMonom->next);
    delete curMonom;
  }
}

void Polynoms::remove(Polynom &p)
{
  ::remove(p.first);
}
