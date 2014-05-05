#pragma once

#include <cstdio>
#include <string>

using namespace std;

const int maxLen = 100000;

///Class which is used to calculate the value of prefix notation
class ExprTree
{
public:
  ExprTree(char *expression, int len);
  ~ExprTree();

  ///Method which prints parsing tree
  string print();
  double result();

  struct ExprTreeNode
  {
    char operation;
    double value;
    ExprTreeNode *left;
    ExprTreeNode *right;

    ExprTreeNode() {}
    ExprTreeNode(double _value) : operation('!'), value(_value), left(nullptr), right(nullptr) {}

  };

private:
  ExprTreeNode *root;

  ExprTreeNode *createNode(char *expression, int first, int last, int *pair);
  double getResult(ExprTreeNode *node);
  string print(ExprTreeNode *node);
  void deleteAll(ExprTreeNode *node);
};
