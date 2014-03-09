#include "outputer.h"

class ConsoleOutputer : public Outputer
{
public:
  ~ConsoleOutputer();

  void out(int **a, int n);
};