#include "polynomial_hash.h"

PolynomialHash::~PolynomialHash() {}

int PolynomialHash::getHash(string s)
{
  const int P = 239017;

  int len = s.size();
  int hash = 0;
  for (int i = 0; i < len; i++)
  {
    hash *= P;
    hash += (unsigned int)s[i];
  }

  return hash;
}

int PolynomialHash::number()
{
  return polynomialCode;
}
