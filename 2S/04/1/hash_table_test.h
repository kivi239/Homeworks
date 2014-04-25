#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hash_table.h"

class HashTableTest : public QObject
{
  Q_OBJECT
public:
  explicit HashTableTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void loadFactorTest()
  {
    HashTable table(2, simpleCode);
    table.add("a", 1);
    table.add("b", 1);

    QVERIFY(table.loadFactor() == 1);
  }

  void equalStringsTest()
  {
    HashTable table(2);
    table.add("aba", 1);
    table.add("aba", 2);

    QVERIFY(table.getOccupied() == 1);
    QVERIFY(table.getAll() == 3);
  }

  void removeTest()
  {
    HashTable table(2);
    table.add("b", 1);
    table.add("a", 1);
    table.remove("a");
    QVERIFY(table.getOccupied() == 1);
  }

  void makeBiggerTest()
  {
    HashTable table(1);
    for (int i = 0; i < 6; i++)
    {
      string toAdd = "";
      toAdd += ('a' + i);
      table.add(toAdd, 1);
    }

    QVERIFY(table.getSize() == 2);
  }

  void equalHashTest()
  {
    HashTable table(1, simpleCode);
    table.add("ab", 1);
    table.add("ba", 1);

    QVERIFY(table.getSize() == 1);
    QVERIFY(table.getOccupied() == 2);
  }

  void changeHashTest()
  {
    HashTable table(10, polynomialCode);
    table.add("ab", 1);
    table.add("ba", 1);
    QVERIFY(table.maxSize() == 1);

    table.setHash(simpleCode);
    QVERIFY(table.maxSize() == 2);
  }

  void statisticTest()
  {
    HashTable table(4, simpleCode);
    table.add("ab", 2);
    table.add("ba", 1);
    table.add("a", 1);
    table.add("0000", 1);
    table.add("abacaba", 2);
    table.add("a", 1);

    table.showStatistics();
  }

};
