#include "pair.h"

///Class for complex numbers
class ComplexNumber : public Pair
{
public:
  ComplexNumber();
  ComplexNumber(double _first, double _second);
  ///Operator which multiplies two complex numbers
  ComplexNumber operator *(ComplexNumber number);
  ComplexNumber operator *(double value);
  ///Method which returns modulus of complex number
  double length();
};
