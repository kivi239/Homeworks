#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "calculatorFunc.h"

class CalculatorTest : public QObject
{
  Q_OBJECT
public:
  explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void addTest()
  {
    CalculatorFunc calc(3, "+");
    QCOMPARE(calc.calc(5), QString("8.000000"));
    QVERIFY(calc.calc(2) == "10.000000");
  }

  void divByZeroTest()
  {
    CalculatorFunc calc(5, "/");
    QVERIFY(calc.calc(0) == "Division by zero!");
  }
};
