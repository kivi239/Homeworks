#include "treeNode.h"

class DivNode : public TreeNode
{
public:
  DivNode(TreeNode *_left, TreeNode *_right);
  ~DivNode();
  double result();
  QString print();

 private:
  TreeNode *left;
  TreeNode *right;
};
