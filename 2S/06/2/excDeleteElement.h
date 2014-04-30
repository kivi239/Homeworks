#include "exception.h"
#include <string>

using namespace std;

class ExcDeleteElement : public Exception
{
public:
  ExcDeleteElement(string mess);
  string printMessage();

private:
  string message;
};
