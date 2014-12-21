#include <test.h>

int main()
{
  Test test;
  QTest::qExec(&test);

  return 0;
}
