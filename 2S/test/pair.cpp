#include "pair.h"

Pair::Pair() : first(0), second(0) {}

Pair::Pair(double _first, double _second) : first(_first), second(_second) {}

Pair::~Pair() {}

Pair Pair::operator *(double value)
{
  return Pair(first * value, second * value);
}

Pair Pair::operator +(Pair pair)
{
  return Pair(first + pair.first, second + pair.second);
}
