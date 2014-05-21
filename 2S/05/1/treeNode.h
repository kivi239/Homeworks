#pragma once
#include <QString>

///Class for expression tree node
class TreeNode
{
public:
  virtual ~TreeNode() = 0;
  virtual double result() = 0;
  virtual QString print() = 0;
};
