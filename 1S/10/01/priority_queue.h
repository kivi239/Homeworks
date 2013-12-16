namespace PriorityQueues
{
  struct Node
  {
    int value;
    char key;
    Node *left;
    Node *right;
  };

  struct Tree
  {
    Node *root;
    Tree *next;
  };                                                                                        

  struct PriorityQueue
  {
    Tree *head;
    Tree *tail;
  };

  PriorityQueue create();
  void add(PriorityQueue &, int value, char key);
  void remove(PriorityQueue &);
  int size(PriorityQueue &);
  void merge(PriorityQueue &);
  void traversal(PriorityQueue &, long long *save);
  void out(PriorityQueue &);
}
