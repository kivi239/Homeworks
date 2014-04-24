#pragma once

#include <iostream>
#include <string>

using namespace std;

enum Hashes
{
  polynomialCode,
  simpleCode
};

class HashFunction
{
public:
  virtual ~HashFunction();

  virtual int getHash(string s) = 0;
  virtual int number() = 0;
};
