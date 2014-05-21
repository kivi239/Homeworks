#include "sumNode.h"

SumNode::SumNode(TreeNode *_left, TreeNode *_right) : left(_left), right(_right) {}

SumNode::~SumNode()
{
  delete left;
  delete right;
}

double SumNode::result()
{
  return left->result() + right->result();
}

QString SumNode::print()
{
  QString res = "( + ";
  res += left->print();
  res += " ";
  res += right->print();
  res += " )";

  return res;
}
