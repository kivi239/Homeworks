#include "pair.h"
#include <QtTest/QtTest>
#include <QtCore/QObject>

class PairTest : public QObject
{
  Q_OBJECT
public:
  explicit PairTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void sumTest()
  {
    Pair p1(1, 2);
    Pair p2;
    QVERIFY((p1 + p2).first == 1);
    QVERIFY((p1 + p2).second == 2);
  }

  void mulTest()
  {
    Pair p(5, 10);
    QVERIFY((p * 5).first == 25);
    QVERIFY((p * 5).second == 50);
  }
};
