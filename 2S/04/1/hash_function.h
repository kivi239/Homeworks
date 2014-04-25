#pragma once

#include <iostream>
#include <string>

using namespace std;

enum Hashes
{
  polynomialCode,
  simpleCode
};

///Class which is used to calculate hashes of strings
class HashFunction
{
public:
  virtual ~HashFunction();

  virtual int getHash(string s) = 0;
  ///Method which returns simpleCode or PolynomialCode
  virtual int type() = 0;
};
