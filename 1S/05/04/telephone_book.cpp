#include <cstdio>
#include "telephone_book.h"

using namespace Telephones;

bool isEqual(char *s1, char *s2)
{
  for (int i = 0; i < maxName; i++)
    if (s1[i] != s2[i])
      return false;
  return true;
}

TelephoneBook Telephones::create(FILE *f)
{
  int n = 0;
  fscanf(f, "%d", &n);
  TelephoneBook b = {NULL};
  for (int i = 0; i < n; i++) 
  {
    char s[maxName];
    for (int i = 0; i < maxName; i++)
      s[i] = ' ';
    long long num = 0;
    fscanf(f, "%s", s);
    fscanf(f, "%lld", &num);

    TelephoneNumber *newNumber = new TelephoneNumber;
    for (int i = 0; i < maxName; i++)
      newNumber->name[i] = s[i];
    newNumber->number = num;
    newNumber->next = b.head;

    b.head = newNumber;
  }
  return b;
}

void Telephones::add(TelephoneBook &b, char *name, long long number)
{
  TelephoneNumber *newNumber = new TelephoneNumber;
  for (int i = 0; i < maxName; i++)
    newNumber->name[i] = name[i];
  newNumber->number = number;
  newNumber->next = b.head;

  b.head = newNumber;
}

TelephoneNumber * Telephones::find(TelephoneBook &b, char *name)
{
  TelephoneNumber *curNumber = b.head;
  while (curNumber != NULL)                                                                   
  {
    if (isEqual(curNumber->name, name))
      return curNumber;
    curNumber = curNumber->next;
  }
  return curNumber;
}

TelephoneNumber * Telephones::find(TelephoneBook &b, long long number)
{
  TelephoneNumber *curNumber = b.head;
  while (curNumber != NULL)
  {
    if (curNumber->number == number)
      return curNumber;
    curNumber = curNumber->next;
  }
  return curNumber;
}

int Telephones::size(TelephoneBook &b)
{
  int size = 0;
  TelephoneNumber *curNumber = b.head;
  while (curNumber != NULL)
  {
    size++;
    curNumber = curNumber->next;
  }
  return size;
}

void Telephones::save(TelephoneBook &b, FILE *f)
{
  fprintf(f, "%d\n", size(b));
  TelephoneNumber *curNumber = b.head;
  while (curNumber != NULL)
  {
    fprintf(f, "%s %d\n", curNumber->name, curNumber->number);
    curNumber = curNumber->next;                      
  }
}

void deleteAll(TelephoneNumber *curNumber)
{ 
  if (curNumber != NULL)
  {
    deleteAll(curNumber->next);
    delete curNumber;
  }
}

void Telephones::deleteAll(TelephoneBook &book)
{
  ::deleteAll(book.head);
}
