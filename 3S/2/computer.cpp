#include "computer.h"

Computer::Computer(double p) : probability(p), infected(false) {}

double Computer::getProbability()
{
  return probability;
}

void Computer::setInfected(bool isInfected)
{
  infected = isInfected;
}

bool Computer::isInfected()
{
  return infected;
}

