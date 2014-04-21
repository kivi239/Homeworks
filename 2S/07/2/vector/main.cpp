#include <iostream>
#include <vectorTest.h>

int main()
{
  VectorTest vecTest;
  QTest::qExec(&vecTest);

  return 0;
}
