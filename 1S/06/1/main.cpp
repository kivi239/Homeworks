#include <cstdio>
#include "AVLTree.h"                                                                                                      

using namespace AVLTrees;

enum Commands
{
  exitCode,
  addCode,
  descendingCode,
  ascendingCode,
  removeCode,
  printCode,
};

void talkToUser()
{
  printf("Please, enter a command.\n");
  printf("0 - exit\n");
  printf("1 - add value\n");
  printf("2 - print in descending order\n");
  printf("3 - print in ascending order\n");
  printf("4 - remove value\n");                                    
  printf("5 - print in tree format\n");
}

int main()                                                                                                     
{
  AVLTree tree = create();

  int command = 0;
  talkToUser();
  scanf("%d", &command);
  while (command != exitCode)
  {
    if (command == addCode)
    {
      int value = 0;
      scanf("%d", &value);
      add(tree, value);
    }
    else if (command == descendingCode)
      printDescending(tree);
    else if (command == ascendingCode)
      printAscending(tree);
    else if (command == removeCode)
    {
      int value = 0;
      scanf("%d", &value);
      remove(tree, value);
    }
    else if (command = printCode)
      printTree(tree);

    scanf("%d", &command);
  }

  deleteAll(tree);

  return 0;
}    