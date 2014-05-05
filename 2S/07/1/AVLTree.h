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

  AVLTreeNode *&mostLeft(AVLTreeNode *&curNode);
  int height(AVLTreeNode *curNode);
  int balance(AVLTreeNode *curNode);
  void update(AVLTreeNode *curNode);
  AVLTreeNode *leftSpin(AVLTreeNode *curNode);
  AVLTreeNode *rightSpin(AVLTreeNode *curNode);
  AVLTreeNode *find(AVLTreeNode *&curNode, int value);
  void balanceNode(AVLTreeNode *&curNode);
  void add(AVLTreeNode *&curNode, int value);
  void remove(AVLTreeNode *&curNode, int value);
  void deleteAll(AVLTreeNode *&curNode);
  void printAscending(AVLTreeNode *curNode);
  void printDescending(AVLTreeNode *curNode);
  void printTree(AVLTreeNode *curNode);
};

