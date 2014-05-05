#include "exprTree.h"
#include <iostream>
#include <cstring>

using namespace std;

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

ExprTree::ExprTree(char *expression, int len)
{
  root = nullptr;
  if (len == 0)
    return;

  int pair[maxLen];
  for (int i = 0; i < maxLen; i++)
    pair[i] = -1;

  countBracketsPairs(expression, len, pair);
  root = this->createNode(expression, 1, len - 2, pair);
}

double ExprTree::getResult(ExprTreeNode *node)
{
  if (node->operation == '+')
    return node->left->value + node->right->value;
  if (node->operation == '-')
    return node->left->value - node->right->value;
  if (node->operation == '*')
    return node->left->value * node->right->value;
  if (node->operation == '/')
    return node->left->value / node->right->value;

  return 0;
}

ExprTree::ExprTreeNode *ExprTree::createNode(char *expression, int first, int last, int *pair)
{
  ExprTree::ExprTreeNode *newNode = new ExprTree::ExprTreeNode();
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
    newNode->left = new ExprTree::ExprTreeNode(strToInt(expression, beginOfLeft, last));
    beginOfRight = beginOfLeft + sizeOfInt(newNode->left->value) + 1;
  }

  while (beginOfRight <= last && expression[beginOfRight] == ' ')
    beginOfRight++;

  if (expression[beginOfRight] == '(')
    newNode->right = createNode(expression, beginOfRight + 1, pair[beginOfRight] - 1, pair);
  else
  {
    ExprTree::ExprTreeNode *newRightNode = new ExprTree::ExprTreeNode(strToInt(expression, beginOfRight, last));
    newNode->right = newRightNode;
  }

  newNode->value = getResult(newNode);

  return newNode;
}

string ExprTree::print(ExprTreeNode *node)
{
  string res = "";
  if (node->operation != '!')
  {
    res += "( ";
    res += node->operation;
    res += ' ';
    res += print(node->left);
    res += ' ';
    res += print(node->right);
    res += " )";
  }
  else
  {
    char *tmp = new char[20];
    sprintf(tmp, "%.0lf", node->value);
    int len = strlen(tmp);
    for (int i = 0; i < len; i++)
      res += tmp[i];
    delete tmp;
  }

  return res;
}

string ExprTree::print()
{
  return print(root);
}

double ExprTree::result()
{
  return getResult(root);
}

void ExprTree::deleteAll(ExprTreeNode *node)
{
  if (node == nullptr)
      return;
  deleteAll(node->left);
  deleteAll(node->right);
  delete node;
}

ExprTree::~ExprTree()
{
  deleteAll(root);
}
