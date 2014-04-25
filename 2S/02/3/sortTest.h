#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sort.h"
#include <algorithm>

class SortTest : public QObject
{
  Q_OBJECT
public:
  explicit SortTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void minTest()
  {
    int **arr = new int*[1];
    arr[0] = new int[1];
    arr[0][0] = 42;
    Sort sort;
    sort.sort(arr, 0, 0);
    QVERIFY(arr[0][0] == 42);

    delete[] arr[0];
    delete[] arr;
  }

  void test()
  {
    const int SIZE = 10;
    int **arr = new int*[SIZE];
    for (int i = 0; i < SIZE; i++)
      arr[i] = new int[SIZE];

    for (int i = 0; i < SIZE; i++)
      for (int j = 0; j < SIZE; j++)
        arr[i][j] = rand() % SIZE;

    Sort sort;
    sort.sort(arr, 0, SIZE - 1);
    for (int i = 0; i < SIZE - 1; i++)
      QVERIFY(arr[i][0] <= arr[i + 1][0]);
  }

};
