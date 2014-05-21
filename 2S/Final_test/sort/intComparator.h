
#include "comparator.h"

class IntComparator : public Comparator<int>
{
public:
  ~IntComparator() {}
  bool cmp(const int &first, const int &second);

};
