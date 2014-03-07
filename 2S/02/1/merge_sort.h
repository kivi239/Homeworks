#include "sort.h"

class MergeSort : public Sort
{
public:
  MergeSort();
  ~MergeSort();
                                   
  void sort(int *begin, int *end);
};