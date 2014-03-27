#include "calculator.h"

double Calculator::calc(int value1, int value2, char operation)
{
  if (operation == '/' && value2 == 0)
    return error;

  if (operation == '+')
    return value1 + value2;
  if (operation == '-')
    return value1 - value2;
  if (operation == '*')
    return value1 * value2;

   return value1 * 1.0 / value2;
}
