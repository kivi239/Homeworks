#pragma once
#include "generator.h"

class NotRandomGenerator : public Generator
{
public:
  ~NotRandomGenerator();
  double getRandom();
};
