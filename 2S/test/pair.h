#pragma once

///Class for pair of two doubles
class Pair
{
public:
  Pair();
  Pair(double _first, double _second);
  ~Pair();
  ///Operator which mupltiplies coordinates by value
  Pair operator * (double value);
  ///Operator which adds coordinates of two pairs
  Pair operator + (Pair pair);

  double first;
  double second;
};
