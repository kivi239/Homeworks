#include "treeNode.h"

///Class for node with value
class LeafNode : public TreeNode
{
public:
  LeafNode(int _value);
  double result();
  QString print();

private:
  int value;
};
