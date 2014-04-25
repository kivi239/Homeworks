#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "mergeSort.h"
#include "quickSort.h"
#include <algorithm>

class SortTest : public QObject
{
  Q_OBJECT
public:
  explicit SortTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void minTest()
  {
    int *a = new int[1];
    a[0] = 239;
    Sort *sort = new QuickSort();
    sort->sort(a, a + 1);
    QVERIFY(a[0] == 239);
    delete sort;
    sort = new MergeSort();
    sort->sort(a, a + 1);
    QVERIFY(a[0] == 239);
    delete sort;
  }

  void mergeTest()
  {
    const int SIZE = 2000;
    int *a = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
      a[i] = rand() % SIZE;

    MergeSort sort;
    sort.sort(a, a + SIZE);
    for (int i = 0; i < SIZE - 1; i++)
      QVERIFY(a[i + 1] >= a[i]);
  }


  void quickTest()
  {
    const int SIZE = 5;
    int *a = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
      a[i] = rand() % SIZE;

    QuickSort sort;
    sort.sort(a, a + SIZE);
    for (int i = 0; i < SIZE - 1; i++)
      QVERIFY(a[i + 1] >= a[i]);
  }

};
