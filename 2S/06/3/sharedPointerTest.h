#include <QObject>
#include <QtTest/QtTest>
#include "sharedPointer.h"

class SharedPointerTest : public QObject
{
  Q_OBJECT
public:
  explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void createTest()
  {
    int *value = new int(5);
    SharedPointer<int> sPtr(value);
    QVERIFY(sPtr.getCount() == 1);
    QVERIFY(*sPtr.getPointer() == 5);
  }

  void copyTest()
  {
    int *value = new int(17);
    SharedPointer<int> sPtr(value);
    SharedPointer<int> copy(sPtr);
    QVERIFY(sPtr.getCount() == 2);
    QVERIFY(copy.getCount() == 2);
  }

  void assignTest()
  {
    int *value = new int(42);
    SharedPointer<int> sPtr1(value);
    SharedPointer<int> sPtr2 = sPtr1;
    QVERIFY(sPtr1.getCount() == 2);
    QVERIFY(sPtr2.getCount() == 2);
  }
};
