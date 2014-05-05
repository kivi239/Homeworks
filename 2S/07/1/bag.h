#include "AVLTree.h"

class Bag : public AVLTree
{
public:
  Bag();
  ~Bag();
  bool add(int value);
  bool remove(int value);
  bool find(int value);
  void printAscending();
  void printDescending();
  void printTree();
};
