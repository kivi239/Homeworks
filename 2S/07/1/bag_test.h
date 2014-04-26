#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bag.h"

class BagTest : public QObject
{
  Q_OBJECT
public:
  explicit BagTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void addTest()
  {
    Bag *bag = new Bag();
    bag->add(2);
    bag->add(3);
    bag->add(1);
    QVERIFY(bag->find(1));
    QVERIFY(bag->find(2));
    QVERIFY(bag->find(3));
    delete bag;
  }

  void printTest()
  {
    Bag bag;
    for (int i = 0; i < 10; i++)
      bag.add(i);
    bag.printAscending();
    bag.printDescending();
    bag.printTree();
  }

  void removeTest()
  {
    Bag bag;
    bag.add(5);
    bag.add(2);
    QVERIFY(bag.find(5));
    bag.add(5);
    bag.remove(5);
    QVERIFY(!bag.find(5));
    QVERIFY(bag.find(2));
  }

  void minTest()
  {
    Bag bag;
    bag.add(2);
    bag.remove(2);
    bag.printTree();
  }
};
