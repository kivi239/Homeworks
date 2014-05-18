#include "treeNode.h"

class SumNode : public TreeNode
{
public:
  SumNode(TreeNode *_left, TreeNode *_right);
  ~SumNode();
  double result();
  QString print();

 private:
  TreeNode *left;
  TreeNode *right;
};
