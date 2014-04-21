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

    Vector<int, 3> anotherVector;
    anotherVector.array[1] = 5;
    QVERIFY(!anotherVector.isZero());
  }

  void testSumVector()
  {
    Vector<int, 3> vec1;
    vec1.array[0] = 1;
    vec1.array[1] = 2;
    vec1.array[2] = 3;

    Vector<int, 3> vec2;
    vec2.array[0] = 3;
    vec2.array[1] = 2;
    vec2.array[2] = 1;

    Vector<int, 3> vec3;
    vec3.array[0] = 4;
    vec3.array[1] = 4;
    vec3.array[2] = 4;

    QCOMPARE((vec1 + vec2).array[0], vec3.array[0]);
    QCOMPARE((vec1 + vec2).array[1], vec3.array[1]);
    QCOMPARE((vec1 + vec2).array[2], vec3.array[2]);
  }

  void testSubVector()
  {
    Vector<int, 2> vec1;
    vec1.array[0] = 1;
    vec1.array[1] = 2;

    Vector<int, 2> vec2;
    vec2.array[0] = 1;
    vec2.array[1] = 2;

    QVERIFY((vec1 - vec2).isZero());
  }

  void testDotProduct()
  {
    Vector<int, 3> vec1;
    vec1.array[0] = 1;
    vec1.array[1] = 0;
    vec1.array[2] = -2;

    Vector<int, 3> vec2;
    vec2.array[0] = 5;
    vec2.array[1] = 2;
    vec2.array[2] = 1;

    QVERIFY((vec1 * vec2) == 3);
  }

  void testCopyVector()
  {
    Vector<int, 3> vec1;
    vec1.array[1] = 239;
    Vector<int, 3> vec2(vec1);
    QVERIFY((vec1 - vec2).isZero());
  }
};

