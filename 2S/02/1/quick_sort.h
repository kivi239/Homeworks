#include "sort.h"

class QuickSort : public Sort
{
public:
  QuickSort();
  ~QuickSort();

  void sort(int *begin, int *end);
};