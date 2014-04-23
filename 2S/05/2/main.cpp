#include <setTest.h>
#include <iostream>

int main()
{
  SetTest setTest;
  QTest::qExec(&setTest);
  /*Set<int> s;
  s.add(5);
  s.add(2);
  cout << s.find(2) << ' ' << s.find(6) << endl;
  s.print();
  s.add(3);
  s.remove(5);

  Set<int> s2;
  s2.add(2);
  s2.add(4);
  s2.print();

  Set<int> s3 = s2.intersec(s);
  s3.print();

  Set<int> s4;
  s4.add(9);
  Set<int> s5 = s4.un(s);
  s5.print();
  */
  return 0;
}
