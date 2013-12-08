#include <cstdio>
#include "telephone_book.h"

using namespace Telephones;

enum Commands
{
  exitCode,
  addCode,
  findNumberCode,
  findNameCode,
  saveCode
};

void TalkToUser()
{
  printf("Please, enter the command\n");
  printf("0 - exit\n");
  printf("1 - add name and telephone number\n");
  printf("2 - find telephone number\n");
  printf("3 - find name\n");
  printf("4 - save all telephone numbers\n");

}

void do_it(TelephoneBook &b)
{
  int com = 0;
  scanf("%d", &com);
  while (com != exitCode)
  {
    if (com == addCode)
    {
      char s[maxName];
      for (int i = 0; i < maxName; i++)
        s[i] = ' ';
      long long number;
      scanf("%s", s);
      scanf("%d", &number);
      add(b, s, number);
    }
    if (com == findNumberCode)      
    {
      char s[maxName];
      for (int i = 0; i < maxName; i++)
        s[i] = ' ';
      scanf("%s", s);
      TelephoneNumber *foundNumber = find(b, s);
      if (foundNumber == NULL)
        printf("There is not any number with this name\n");
      else
        printf("%lld\n", foundNumber->number);
    }
    if (com == findNameCode)
    {
      long long num = 0;
      scanf("%lld", &num);
      TelephoneNumber *foundNumber = find(b, num);
      if (foundNumber == NULL)
        printf("There is not any name with this number\n");
      else
        printf("%s", foundNumber->name);
    }

    if (com == saveCode)
    {
      FILE *Numbers = fopen("numbers.txt", "wt");
      save(b, Numbers);
      fclose(Numbers);
    }

    scanf("%d", &com);
  }
}

int main()
{
  FILE *Numbers = fopen("numbers.txt", "rt");
  TelephoneBook b = create(Numbers);
  fclose(Numbers);

  TalkToUser();

  do_it(b);
  deleteAll(b);

  return 0;
}
                                   