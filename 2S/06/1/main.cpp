#include "class.h"
#include "exception.h"

#include <iostream>

int main()
{
  try
  {
    Class c[7];
    throw Exception();
  }
  catch(...)
  {
    std::cout << "Catch" << std::endl;
  }

  return 0;
}
