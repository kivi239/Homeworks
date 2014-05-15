#include "calculator.h"
#include <QApplication>
#include "calculatorTest.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  CalculatorTest calcTest;
  QTest::qExec(&calcTest);

  Calculator w;
  w.show();

  return a.exec();
}
