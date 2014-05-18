#pragma once
#include <cstdio>
#include "treeNode.h"

///Class which is used to calculate the value of prefix notation
class ExprTree
{
public:
  ExprTree(QString from);
  ~ExprTree();

  ///Method which prints parsing tree
  QString print();
  double result();

private:
  TreeNode *root;
  ///Method which creates node that corresponds to substring
  TreeNode *createNode(QString from, int first, int last, int *pair);
};
