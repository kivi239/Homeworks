#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "stringComparator.h"
#include "intComparator.h"
#include "intDecComparator.h"
#include <ctime>
#include "bubbleSort.h"

class SortTest : public QObject
{
  Q_OBJECT
public:
  explicit SortTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void compTest()
  {
    Comparator<int> *comp = new IntComparator();
    QVERIFY(comp->cmp(2, 3));
    delete comp;
  }

  void sortIntTest()
  {
    srand(time(NULL));
    Comparator<int> *comp = new IntComparator();
    const int size = 20;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
      array[i] = 0;
    for (int i = 0; i < size; i++)
      array[i] = rand() % size;

    BubbleSort sort;

    sort.sort(array, size, comp);
    for (int i = 0; i < size - 1; i++)
      QVERIFY(array[i] <= array[i + 1]);
    for (int i = 0; i < size; i++)
      printf("%d ", array[i]);
    printf("\n");

    delete[] array;
    delete comp;
  }

  void sortIntDecTest()
  {
    srand(time(NULL));
    Comparator<int> *comp = new IntDecComparator();
    const int size = 20;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
      array[i] = 0;
    for (int i = 0; i < size; i++)
      array[i] = rand() % size;

    BubbleSort sort;

    sort.sort(array, size, comp);
    for (int i = 0; i < size - 1; i++)
      QVERIFY(array[i] >= array[i + 1]);
    for (int i = 0; i < size; i++)
      printf("%d ", array[i]);
    printf("\n");

    delete[] array;
    delete comp;
  }
};
