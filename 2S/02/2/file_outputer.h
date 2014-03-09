#include "outputer.h"

class FileOutputer : public Outputer
{
public:
  ~FileOutputer();

  void out(int **a, int n);
};