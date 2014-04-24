#pragma once

#include "hash_function.h"

class SimpleHash : public HashFunction
{
public:
  ~SimpleHash();

  int getHash(string s);
  int number();
};
