#include "outputer.h"

///Class which is used to print the spiral traversal of matrix to console
class ConsoleOutputer : public Outputer
{
public:
  ~ConsoleOutputer();

  void out(int **a, int n);
};