#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "list.h"

class ListTest : public QObject
{
  Q_OBJECT
public:
  explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void addTest()
  {
    List l;
    l.add(2, "abacaba", 1);
    l.add(2, "bacaba", 1);

    QVERIFY(l.size() == 2);
  }

  void removeTest()
  {
    List l;
    l.add(2, "ab", 1);
    l.remove("a");
    QVERIFY(l.size() == 1);
    l.remove("ab");
    QVERIFY(l.size() == 0);
  }


};
