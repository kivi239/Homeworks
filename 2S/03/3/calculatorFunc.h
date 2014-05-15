#pragma once
#include <QString>

class CalculatorFunc
{
public:
  CalculatorFunc();
  CalculatorFunc(double number, QString operation);
  ~CalculatorFunc();
  QString calc(double number);

private:
  double lastNumber;
  QString lastOperation;
};
