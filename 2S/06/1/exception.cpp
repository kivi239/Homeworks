#include "exception.h"
#include <iostream>

Exception::~Exception()
{
  std::cout << "Exception is deleted!" << std::endl;
}
