#include "comparator.h"

///Class to compare numbers in decrease order
class IntDecComparator : public Comparator<int>
{
public:
  ~IntDecComparator() {}
  bool cmp(const int &first, const int &second);
};
