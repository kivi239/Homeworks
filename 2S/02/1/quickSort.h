#include "sort.h"

///Class which is used to sort an array with using quick sort
class QuickSort : public Sort
{
public:
  ~QuickSort();

  void sort(int *begin, int *end);
};
