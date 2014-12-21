#pragma once

class Generator
{
public:
  virtual ~Generator();
  virtual double getRandom() = 0;
};

