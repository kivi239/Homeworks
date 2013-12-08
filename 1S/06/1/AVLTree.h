namespace AVLTrees
{
  struct AVLTreeNode
  {
    int value;
    int height;
    AVLTreeNode *left;
    AVLTreeNode *right;
  };

  struct AVLTree
  {
    AVLTreeNode *root;
  };

  AVLTree create();
  bool add(AVLTree &, int);
  bool remove(AVLTree &, int);
  bool find(AVLTree &, int);
  void deleteAll(AVLTree &);            
  void printAscending(AVLTree &);
  void printDescending(AVLTree &);
  void printTree(AVLTree &);
}