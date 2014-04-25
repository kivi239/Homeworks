#include <iostream>
#include "simple_hash.h"
#include "polynomial_hash.h"
#include "list_test.h"
#include "hash_table_test.h"

int main()
{
  ListTest listTest;
  QTest::qExec(&listTest);

  HashTableTest hashTableTest;
  QTest::qExec(&hashTableTest);

  return 0;
}
