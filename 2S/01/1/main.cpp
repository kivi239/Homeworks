#include <cstdio>
#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include <iostream>

using namespace std;

enum Commands
{
  exitCode,
  addCode,
  removeCode,
  printCode,
  sizeCode,
};

void talkToUser()
{
  printf("Please, enter the command\n");
  printf("0 - exit\n");
  printf("1 - add a value to sorted list\n");
  printf("2 - remove a value from sorted list\n");
  printf("3 - print list\n");
}

int main()
{
  talkToUser();
  
  SinglyLinkedList singleL;
  DoublyLinkedList doubleL;

  int command = 0;
  scanf("%d", &command);
  while (command != exitCode)
  {
    if (command == addCode)
    {
      int value;
      scanf("%d", &value);
      singleL.add(value);
      doubleL.add(value);
    }
    if (command == removeCode)
    {
      int value;
      scanf("%d", &value);
      singleL.remove(value);
      doubleL.remove(value);
    }
    if (command == printCode)
    {
      singleL.print();
      doubleL.print();
    }

    scanf("%d", &command);
  }
  
  return 0;
}
      