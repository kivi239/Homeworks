#include "treeNode.h"

class SubNode : public TreeNode
{
public:
  SubNode(TreeNode *_left, TreeNode *_right);
  ~SubNode();
  double result();
  QString print();

 private:
  TreeNode *left;
  TreeNode *right;
};
