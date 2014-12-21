#include "randomgenerator.h"
#include <algorithm>

RandomGenerator::~RandomGenerator() {}

double RandomGenerator::getRandom()
{
  return (rand() % 100 + 1) * 0.01;
}
