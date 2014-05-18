#include "treeNode.h"

class MulNode : public TreeNode
{
public:
  MulNode(TreeNode *_left, TreeNode *_right);
  ~MulNode();
  double result();
  QString print();

 private:
  TreeNode *left;
  TreeNode *right;
};
