#include <cstdio>
#include "expr_tree.h"
#include <cstring>

using namespace ExprTrees;

int main()
{
  printf("Please, enter a prefix notation\n");
  
  char expression[maxLen];
  for (int i = 0; i < maxLen; i++)
    expression[i] = '\0';

  gets(expression);

  int length = strlen(expression);
  for (int i = 0; i < length; i++)
    expression[i] = expression[i + 1];
  expression[length - 2] = '\0'; 
  length -= 2;

  ExprTree tree = create(expression, length);
   
  print(tree);
  printf("\n%.4lf\n", result(tree));

  deleteAll(tree);

  return 0;
}