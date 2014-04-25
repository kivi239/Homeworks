#include "simple_hash.h"

SimpleHash::~SimpleHash() {}

int SimpleHash::getHash(string s)
{
  int len = s.size();
  int hash = 0;
  for (int i = 0; i < len; i++)
    hash += (unsigned int)s[i];

  return hash;
}

int SimpleHash::type()
{
  return simpleCode;
}
