#include <cstdio>

namespace Telephones
{
  const int maxName = 25;
  
  struct TelephoneNumber
  {
    char name[maxName];
    long long number;
    TelephoneNumber *next;
  };
  struct TelephoneBook
  {                                                                                                                     
    TelephoneNumber *head;
  };

  TelephoneBook create(FILE *);
  void add(TelephoneBook &, char *, long long);
  TelephoneNumber *find(TelephoneBook &, char *	);
  TelephoneNumber *find(TelephoneBook &, long long);
  void save(TelephoneBook &, FILE *);
  int size(TelephoneBook &);
  void deleteAll(TelephoneBook &);
}         