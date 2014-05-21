#include <algorithm>
#include "comparator.h"
#include <cstdio>
#include <QDebug>

///Class for bubble sort
class BubbleSort
{
public:
  ~BubbleSort() {}

  template<typename T>
  void sort(T *array, int size, Comparator<T> *comp);

};

template<typename T>
void BubbleSort::sort(T *array, int size, Comparator<T> *comp)
{
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size - 1; j++)
    {
      if (comp->cmp(array[j + 1], array[j]))
      {
        T temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
}
