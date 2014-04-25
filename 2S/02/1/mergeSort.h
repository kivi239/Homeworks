#include "sort.h"

///Class which is used to sort an array with using merge sort
class MergeSort : public Sort
{
public:
  ~MergeSort();

  void sort(int *begin, int *end);
};
