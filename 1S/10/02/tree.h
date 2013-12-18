#include <cstdio>

namespace Trees
{
  struct Node
  {
    char key;
    Node *left;
    Node *right;
  };

  struct Tree
  {
    Node *root;
    Tree *next;
  };                                                                                        

  Tree build(FILE *);
  void printString(Tree &tree, FILE *in, FILE *out);
  void remove(Tree &);
}
