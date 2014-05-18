#include "divNode.h"

DivNode::DivNode(TreeNode *_left, TreeNode *_right) : left(_left), right(_right) {}

DivNode::~DivNode()
{
  delete left;
  delete right;
}

double DivNode::result()
{
  return left->result() / right->result();
}

QString DivNode::print()
{
  QString res = "( / ";
  res += left->print();
  res += " ";
  res += right->print();
  res += " )";

  return res;
}




