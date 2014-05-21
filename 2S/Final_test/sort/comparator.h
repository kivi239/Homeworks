#pragma once

template<typename T>
class Comparator
{
public:
  virtual ~Comparator() {}

  virtual bool cmp(const T &fisrt, const T &second) = 0;
};
