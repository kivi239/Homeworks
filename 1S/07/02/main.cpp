#include <cstdio>
#include <cstring>
#include "String.h"

using namespace Strings;

bool test0()
{
  char text[20] = "hello, world!";

  String s = create(text, 13);

  print(s);
  puts("\n");

  remove(s);

  return true;
}

bool test1()
{
  char t1[10] = "hello,";  
  char t2[10] = "world!!!";

  String s1 = create(t1, 6);
  String s2 = create(t2, 8);

  print(s1);
  puts("");
  print(s2);
  puts("");
  
  concatenation(s2, s1);

  print(s1);
  puts("\n");

  remove(s1);                                   
  remove(s2);

  return true; 
} 

bool test2()       
{
  char t[20] = "blablabla";
  String s = create(t, 9);
  print(s);
  printf(" %d\n", length(s));

  remove(s);

  return true;
}

bool test3()
{          
  char t1[10] = "abacaba";
  char t2[10] = "aba";
  char t3[10] = "daba";

  String s1 = create(t1, 7);
  String s2 = create(t2, 3);
  String s3 = create(t3, 4);

  concatenation(s3, s2);

  print(s1);
  printf(" ");
  print(s2);
  printf(" %d\n\n", (int)areEqual(s1, s2));

  remove(s1);
  remove(s2);
  remove(s3);

  return true;
}

bool test32()
{          
  char t1[10] = "abacaba";
  char t2[10] = "aba";
  char t3[10] = "caba";

  String s1 = create(t1, 7);
  String s2 = create(t2, 3);
  String s3 = create(t3, 4);

  concatenation(s3, s2);

  print(s1);
  printf(" ");
  print(s2);
  printf(" %d\n\n", (int)areEqual(s1, s2));

  remove(s1);
  remove(s2);
  remove(s3);

  return true;
}

bool test4()
{
  char t1[20] = "it is a string";
  String s = create(t1, 14);
  char *t2 = convertToChar(s);

  puts(t2);
  print(s);
  puts("\n");
  
  remove(s);
  delete[] t2;

  return true;
}

bool test5()
{
  char t1[10] = "abacaba";
  String s1 = create(t1, 7);

  String s2 = substr(s1, 1, 5);                                                                               
  print(s2);
  puts("\n");

  remove(s1);
  remove(s2);

  return true;
}

bool test6()
{
  char t[10] = "blabla";
  String s = create(t, 6);
  String s2 = clone(s);

  print(s);
  puts("");
  print(s2);

  remove(s);
  remove(s2);

  return true;
}

int main()
{
  test0();
  test1();                                                                 
  test2();
  test3();    
  test32();
  test4();
  test5();
  test6();

  return 0;
}       