#include "outputer.h"

///Class which is used to print the spiral traversal of matrix to file
class FileOutputer : public Outputer
{
public:
  ~FileOutputer();

  void out(int **a, int n);
};