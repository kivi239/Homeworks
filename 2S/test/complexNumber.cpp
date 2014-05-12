#include "complexNumber.h"
#include <cmath>

ComplexNumber::ComplexNumber() : Pair(Pair()) {}

ComplexNumber::ComplexNumber(double _first, double _second) : Pair(Pair(_first, _second)) {}

double ComplexNumber::length()
{
  return sqrt(first * first + second * second);
}

ComplexNumber ComplexNumber::operator *(ComplexNumber number)
{
  return ComplexNumber(first * number.first + second * number.second, first * number.second - second * number.first);
}

ComplexNumber ComplexNumber::operator *(double value)
{
  return ComplexNumber(first * value, second * value);
}
