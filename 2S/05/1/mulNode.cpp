#include "mulNode.h"

MulNode::MulNode(TreeNode *_left, TreeNode *_right) : left(_left), right(_right) {}

MulNode::~MulNode()
{
  delete left;
  delete right;
}

double MulNode::result()
{
  return left->result() * right->result();
}

QString MulNode::print()
{
  QString res = "( * ";
  res += left->print();
  res += " ";
  res += right->print();
  res += " )";

  return res;
}


