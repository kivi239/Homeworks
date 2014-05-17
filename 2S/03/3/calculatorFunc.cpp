#include "calculatorFunc.h"

CalculatorFunc::CalculatorFunc() : lastNumber(0), lastOperation("!") {}

CalculatorFunc::CalculatorFunc(double number, QString operation) : lastNumber(number), lastOperation(operation) {}

CalculatorFunc::~CalculatorFunc() {}

QString CalculatorFunc::calc(double number)
{
  double answer = lastNumber;
  if (lastOperation == "!")
    answer = number;
  if (lastOperation == "+")
    answer += number;
  if (lastOperation == "-")
    answer -= number;
  if (lastOperation == "*")
    answer *= number;
  if (lastOperation == "/")
  {
    if (number == 0)
    {
      lastNumber = 0;
      return "Division by zero!";
    }
    answer /= number;
  }

  lastNumber = answer;
  char *str = new char[20];
  std::setlocale(LC_NUMERIC, "C");
  sprintf(str, "%.6lf", answer);
  int len = strlen(str);
  QString result = "";
  for (int i = 0; i < len; i++)
    result += str[i];

  delete[] str;
  return result;
}
