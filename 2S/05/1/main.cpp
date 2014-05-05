#include <cstring>
#include <iostream>
#include "exprTreeTest.h"

using namespace std;

int main()
{
  ExprTreeTest exprTreeTest;
  QTest::qExec(&exprTreeTest);

  return 0;
}
