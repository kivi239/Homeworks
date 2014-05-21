#include "exprTree.h"
#include <iostream>
#include <cstring>
#include "sumNode.h"
#include "subNode.h"
#include "mulNode.h"
#include "divNode.h"
#include "leafNode.h"

using namespace std;

void countBracketsPairs(QString expression, int* pair)
{
  int balance = 0;
  int len = expression.size();
  int stack[len];
  for (int i = 0; i < len; i++)
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

ExprTree::ExprTree(QString from)
{
  root = nullptr;
  int len = from.size();
  if (len == 0)
    return;

  int pair[len];
  for (int i = 0; i < len; i++)
    pair[i] = -1;

  countBracketsPairs(from, pair);
  root = createNode(from, 1, len - 2, pair);
}

double ExprTree::result()
{
  return root->result();
}

int strToInt(QString expression, int first, int last)
{
  int value = 0;
  int curId = first;
  while (curId <= last && expression[curId].toLatin1() != ' ')
  {
    value *= 10;
    value += expression[curId].toLatin1() - '0';
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

TreeNode *ExprTree::createNode(QString expression, int first, int last, int *pair)
{
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
  int beginOfLeft = first + 1;
  int beginOfRight = -1;
  while (beginOfLeft <= last && expression[beginOfLeft] == ' ')
    beginOfLeft++;

  if (expression[beginOfLeft] == '(')
  {
    left = createNode(expression, beginOfLeft + 1, pair[beginOfLeft] - 1, pair);
    beginOfRight = pair[beginOfLeft] + 1;
  }
  else
  {
    left = new LeafNode(strToInt(expression, beginOfLeft, last));
    beginOfRight = beginOfLeft + sizeOfInt(left->result()) + 1;
  }

  while (beginOfRight <= last && expression[beginOfRight] == ' ')
    beginOfRight++;

  if (expression[beginOfRight] == '(')
    right = createNode(expression, beginOfRight + 1, pair[beginOfRight] - 1, pair);
  else
    right = new LeafNode(strToInt(expression, beginOfRight, last));

  TreeNode *newNode = nullptr;
  if (expression[first].toLatin1() == '+')
    newNode = new SumNode(left, right);
  if (expression[first].toLatin1() == '-')
    newNode = new SubNode(left, right);
  if (expression[first].toLatin1() == '*')
    newNode = new MulNode(left, right);
  if (expression[first].toLatin1() == '/')
    newNode = new DivNode(left, right);

  return newNode;
}

ExprTree::~ExprTree()
{
  delete root;
}

QString ExprTree::print()
{
  return root->print();
}
