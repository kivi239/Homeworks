#include "list.h"

///Class, in which every element can exist only one time
class UniqueList : List
{
public:
  UniqueList();
  void add(int value);
  void remove(int value);
  int size();
};
