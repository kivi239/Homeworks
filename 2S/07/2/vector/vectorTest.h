#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "vector.h"

class VectorTest : public QObject
{
  Q_OBJECT
public:
  explicit VectorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void testZeroVector()
  {
    Vector<int, 5> newVector;
    QVERIFY(newVector.isZero());

    int arr[3] = {0, 5, 0};
    Vector<int, 3> anotherVector(arr);
    QVERIFY(!anotherVector.isZero());
  }

  void testSumVector()
  {
    int arr1[3] = {1, 2, 3};
    Vector<int, 3> vec1(arr1);

    int arr2[3] = {3, 2, 1};
    Vector<int, 3> vec2(arr2);

    int arr3[3] = {4, 4, 4};
    Vector<int, 3> vec3(arr3);

    QCOMPARE((vec1 + vec2).array[0], vec3.array[0]);
    QCOMPARE((vec1 + vec2).array[1], vec3.array[1]);
    QCOMPARE((vec1 + vec2).array[2], vec3.array[2]);
  }

  void testSubVector()
  {
    int arr[2] = {1, 2};
    Vector<int, 2> vec1(arr);
    Vector<int, 2> vec2(arr);

    QVERIFY((vec1 - vec2).isZero());
  }

  void testDotProduct()
  {
    int arr1[3] = {1, 0, -2};
    Vector<int, 3> vec1(arr1);

    int arr2[3] = {5, 2, 1};
    Vector<int, 3> vec2(arr2);

    QVERIFY((vec1 * vec2) == 3);
  }

  void testCopyVector()
  {
    int arr[3] = {0, 239, 0};
    Vector<int, 3> vec1(arr);
    Vector<int, 3> vec2(vec1);
    QVERIFY(vec1 == vec2);
  }
};

