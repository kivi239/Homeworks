#include <iostream>
#include "simple_hash.h"
#include "polynomial_hash.h"
#include "listTest.h"
#include "hash_tableTest.h"

int main()
{
  ListTest listTest;
  QTest::qExec(&listTest);

  HashTableTest hashTableTest;
  QTest::qExec(&hashTableTest);


  return 0;
}
