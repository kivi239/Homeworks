#include <string>
#include "exception.h"

using namespace std;

class ExcAddElement : public Exception
{
public:
  ExcAddElement(string mess);
  string printMessage();

private:
  string message;
};
