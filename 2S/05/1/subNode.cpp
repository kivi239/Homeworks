#include "subNode.h"

SubNode::SubNode(TreeNode *_left, TreeNode *_right) : left(_left), right(_right) {}

SubNode::~SubNode()
{
  delete left;
  delete right;
}

double SubNode::result()
{
  return left->result() - right->result();
}

QString SubNode::print()
{
  QString res = "( - ";
  res += left->print();
  res += " ";
  res += right->print();
  res += " )";

  return res;
}

