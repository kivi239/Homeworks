#include <iostream>
#include "listTest.h"

using namespace std;

int main()
{
  ListTest listTest;
  QTest::qExec(&listTest);


  return 0;
}
