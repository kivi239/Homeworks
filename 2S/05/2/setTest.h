#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"

class SetTest : public QObject
{
  Q_OBJECT
public:
  explicit SetTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void addTest()
  {
    Set<int> s;
    s.add(5);
    s.add(3);

    QVERIFY(s.find(3));
    QVERIFY(s.find(5));
  }

  void removeTest()
  {
    Set<int> s;
    s.add(5);
    s.add(2);
    s.add(3);
    s.remove(2);
    QVERIFY(!s.find(2));
  }

  void areEqualTest()
  {
    Set<int> s1;
    s1.add(2);
    s1.add(10);

    Set<int> s2;
    s2.add(10);
    s2.add(2);

    QVERIFY(s1 == s2);
  }

  void intersecTest()
  {
    Set<int> s1;
    s1.add(2);
    s1.add(3);

    Set<int> s2;
    s2.add(5);
    s2.add(2);

    Set<int> s3;
    s3.add(2);

    Set<int> s4 = s2.intersec(s1);
    Set<int> s5 = s1.intersec(s2);
    QVERIFY(s3 == s4);
    QVERIFY(s4 == s5);
  }

  void unionTest()
  {
    Set<int> s1;
    s1.add(9);
    s1.add(2);

    Set<int> s2;
    s2.add(3);

    Set<int> s3 = s1.un(s2);
    Set<int> s4;
    s4.add(9);
    s4.add(2);
    s4.add(3);

    QVERIFY(s3 == s4);
  }

};
