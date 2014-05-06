#include "sharedPointerTest.h"

int main()
{
  SharedPointerTest sPtrTest;
  QTest::qExec(&sPtrTest);

  return 0;
}
