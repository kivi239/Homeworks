#pragma once

#include "hash_function.h"

class PolynomialHash : public HashFunction
{
public:
  ~PolynomialHash();

  int getHash(string s);
  int type();
};
