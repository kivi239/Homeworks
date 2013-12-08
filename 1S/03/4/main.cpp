#include <cstdio>
#include "list.h"
#include <iostream>

using namespace std;

using namespace Lists;

enum Commands
{
  exitCode,
  addCode, 
  removeCode,
  printCode
};

void talkToUser(bool aLotToSay)
{
  printf("Please, enter the command\n");
  if (!aLotToSay)
    return;
  printf("0 - exit\n");
  printf("1 - add a value to sorted list\n");
  printf("2 - remove a value from sorted list\n");
  printf("3 - print list\n");
}

int main()
{
  List l = create();
  int command = 0;
  
  talkToUser(true);
  scanf("%d", &command);
  while (command != exitCode)
  {
    if (command == addCode)
    {
      int value = 0;
      scanf("%d", &value);
      add(l, value);
    }
    if (command == removeCode)
    {
      int value = 0;
      scanf("%d", &value);
      remove(l, value);
    }
    if (command == printCode)
      print(l);
    
    talkToUser(false);
    scanf("%d", &command);
  }

  deleteAll(l.head);

  return 0;
}