#include <cstdio>
#include <cstring>
#include "expr_tree.h"

using namespace ExprTrees;

void countBracketsPairs(char *expression, int len, int* pair)
{
  int balance = 0;
  int stack[maxLen];
  for (int i = 0; i < maxLen; i++)
    stack[i] = -1;
  for (int i = 0; i < len; i++)
  {
    if (expression[i] == '(')
      stack[balance++] = i;
    if (expression[i] == ')')
    {
      pair[stack[balance - 1]] = i;
      balance--;                                
    }
  }
}

int strToInt(char *expression, int first, int last)
{
  int value = 0;
  int curId = first;
  while (curId <= last && expression[curId] != ' ')
  {
    value *= 10;
    value += expression[curId] - '0';
    curId++;
  }
  return value;
}

int sizeOfInt(int value)
{
  int size = 0;
  while (value > 0)
  {
    size++;
    value /= 10;
  }
  return size;
}

double result(ExprTreeNode *curNode)
{
  if (curNode->operation == '+')
    return curNode->left->value + curNode->right->value;
  if (curNode->operation == '-')
    return curNode->left->value - curNode->right->value;
  if (curNode->operation == '*')
    return curNode->left->value * curNode->right->value;
  if (curNode->operation == '/')
    return curNode->left->value / curNode->right->value;

  return 0;
}

ExprTreeNode *createLeaf(int value)
{
  ExprTreeNode *newNode = new ExprTreeNode;
  newNode->value = value;
  newNode->operation = '!';
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

ExprTreeNode *createNode(char *expression, int first, int last, int *pair)
{
  ExprTreeNode *newNode = new ExprTreeNode;
  newNode->operation = expression[first];
  
  int beginOfLeft = first + 1;
  int beginOfRight = -1;
  while (beginOfLeft <= last && expression[beginOfLeft] == ' ')
    beginOfLeft++;

  if (expression[beginOfLeft] == '(')
  {                                       
    newNode->left = createNode(expression, beginOfLeft + 1, pair[beginOfLeft] - 1, pair);
    beginOfRight = pair[beginOfLeft] + 1;
  }
  else
  {
    newNode->left = createLeaf(strToInt(expression, beginOfLeft, last));
    beginOfRight = beginOfLeft + sizeOfInt(newNode->left->value) + 1;
  }

  while (beginOfRight <= last && expression[beginOfRight] == ' ')
    beginOfRight++;

  if (expression[beginOfRight] == '(')
    newNode->right = createNode(expression, beginOfRight + 1, pair[beginOfRight] - 1, pair);
  else
  {
    ExprTreeNode *newRightNode = createLeaf(strToInt(expression, beginOfRight, last));
    newNode->right = newRightNode;
  }
  
  newNode->value = result(newNode);
  
  return newNode;                                                                                                       
} 

ExprTree ExprTrees::create(char *expression, int len)
{
  ExprTree tree = {NULL};

  if (len == 0)
    return tree;

  int pair[maxLen];
  for (int i = 0; i < maxLen; i++)
    pair[i] = -1;

  countBracketsPairs(expression, len, pair);

  tree.root = createNode(expression, 0, len - 1, pair);

  return tree;
}

void print(ExprTreeNode *curNode)
{
  if (curNode->operation != '!')
  {
    printf("(");
    print(curNode->left);
    printf(" %c ", curNode->operation);
    print(curNode->right);
    printf(")"); 
  }
  else
    printf("%.0lf", curNode->value); 
}

void ExprTrees::print(ExprTree &tree)
{
  ::print(tree.root);
}

double ExprTrees::result(ExprTree &tree)
{
  return tree.root->value;
}

void deleteAll(ExprTreeNode *curNode)
{
  if (curNode == NULL)
    return;
  deleteAll(curNode->left);
  deleteAll(curNode->right);
  delete curNode;
}

void ExprTrees::deleteAll(ExprTree &tree)
{
  ::deleteAll(tree.root);
}
