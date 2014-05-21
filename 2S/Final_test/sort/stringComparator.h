#include "comparator.h"
#include <string>

class StringComparator : public Comparator<std::string>
{
public:
  ~StringComparator() {}
  bool cmp(const std::string &first, const std::string &second);

};
