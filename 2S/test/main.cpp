#include "complexNumberTest.h"
#include "pairTest.h"

int main()
{
  ComplexNumberTest complexNumberTest;
  QTest::qExec(&complexNumberTest);

  PairTest pairTest;
  QTest::qExec(&pairTest);

  return 0;
}
