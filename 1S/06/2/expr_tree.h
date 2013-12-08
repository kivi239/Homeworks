namespace ExprTrees                                                                                   
{
  const int maxLen = 100000;
  
  struct ExprTreeNode 
  {
    char operation;
    double value;
    ExprTreeNode *left;
    ExprTreeNode *right;
  };

  struct ExprTree                                                  
  {
    ExprTreeNode *root;
  };

  ExprTree create(char *expression, int len);
  void print(ExprTree &);
  double result(ExprTree &);
  void deleteAll(ExprTree &);
}