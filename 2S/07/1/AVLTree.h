///Class for AVL tree
class AVLTree
{
public:
  AVLTree();
  ~AVLTree();

protected:
  struct AVLTreeNode
  {
    int value;
    int height;
    ///This field is necessary for multi set
    int amount;
    AVLTreeNode *left;
    AVLTreeNode *right;

    AVLTreeNode() {}
    AVLTreeNode(int _value, int _height, int _amount, AVLTreeNode *_left, AVLTreeNode *_right)
    {
      value = _value;
      amount = _amount;
      height = _height;
      left = _left;
      right = _right;
    }
  };

  AVLTreeNode *root;
  ///This method returns the most left node in the tree
  AVLTreeNode *&mostLeft(AVLTreeNode *&curNode);
  int height(AVLTreeNode *curNode);
  ///This method returns the difference between left son's and right son's height
  int balance(AVLTreeNode *curNode);
  void update(AVLTreeNode *curNode);
  ///This method makes left spin of node
  AVLTreeNode *leftSpin(AVLTreeNode *curNode);
  ///This method makes right spin of node
  AVLTreeNode *rightSpin(AVLTreeNode *curNode);
  AVLTreeNode *find(AVLTreeNode *&curNode, int value);
  void balanceNode(AVLTreeNode *&curNode);
  void add(AVLTreeNode *&curNode, int value);
  void remove(AVLTreeNode *&curNode, int value);
  void deleteAll(AVLTreeNode *&curNode);
  ///This method prints tree's elements in acsending order
  void printAscending(AVLTreeNode *curNode);
  ///This method prints tree's elements in descending order
  void printDescending(AVLTreeNode *curNode);
  ///This method prints the tree: value of node, then left son, and then right son
  void printTree(AVLTreeNode *curNode);
};

