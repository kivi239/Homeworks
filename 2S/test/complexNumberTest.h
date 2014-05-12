#include <QtTest/QtTest>
#include <QtCore/QObject>
#include "complexNumber.h"

class ComplexNumberTest : public QObject
{
  Q_OBJECT
public:
  explicit ComplexNumberTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void createTest()
  {
    ComplexNumber number;
    QVERIFY(number.first == 0);
    QVERIFY(number.second == 0);
  }

  void constructorTest()
  {
    ComplexNumber number(2, 3);
    QVERIFY(number.first == 2);
    QVERIFY(number.second == 3);
  }

  void lengthTest()
  {
    ComplexNumber number(3, 4);
    QVERIFY(number.length() == 5);
  }

  void sumTest()
  {
    ComplexNumber number1(1, 2);
    ComplexNumber number2(10, 10);

    QVERIFY((number1 + number2).first == 11);
    QVERIFY((number1 + number2).second == 12);
  }

  void mulTest()
  {
    ComplexNumber number1(1, 2);
    ComplexNumber number2(2, 4);

    QVERIFY((number1 * number2).first == 10);
    QVERIFY((number1 * number2).second == 0);
  }

  void mulValueTest()
  {
    ComplexNumber number(3, 4);
    QVERIFY(number.length() * 4 == (number * 4).length());
  }

};
