#include <cstdio>
#include "polynom.h"
#include <cstring>

using namespace Polynoms;

enum Commands
{
  exitCode,
  compareCode, 
  valueCode, 
  sumCode
};

void talkToUser()
{
  puts("1 -- compare two polynoms");
  puts("2 -- calculate the value of the polynom at x");
  puts("3 -- calculate the sum of two polynoms");
  puts("0 -- exit");
}
 
void talkForValue(Polynom &p, int &x)
{
  int deg = 0;
  puts("Please, enter the degree of the polynom");
  scanf("%d", &deg);
  puts("Please, enter the coefficients in decreasing order of degrees");
  for (int i = 0; i <= deg; i++)
  {
    int coeff = 0;                                                                                
    scanf("%d", &coeff);
    add(p, coeff, deg - i);
  }
  puts("Please, enter x");
  scanf("%d", &x);
}

void talk(Polynom &p, Polynom &q)
{
  int degP = 0;
  puts("Please, enter the degree of P");
  scanf("%d", &degP);
  puts("Please, enter the coefficients in decreasing order of degrees");
  for (int i = 0; i <= degP; i++)
  {
    int coeff = 0;
    scanf("%d", &coeff);
    add(p, coeff, degP - i);
  }

  int degQ = 0;
  puts("Please, enter the degree of Q");
  scanf("%d", &degQ);
  puts("Please, enter the coefficients in decreasing order of degrees");
  for (int i = 0; i <= degQ; i++)
  {
    int coeff = 0;
    scanf("%d", &coeff);
    add(q, coeff, degQ - i);
  }
}

int main()
{
  int command = 0;
  talkToUser();
  scanf("%d", &command);
  while (command != exitCode)
  {
    if (command == valueCode)
    {
      Polynom p = create();                                                                  
      int x = 0;
      talkForValue(p, x);
      printf("%d\n", value(p, x));
      remove(p);
    }
    if (command == sumCode)
    {
      Polynom p = create();
      Polynom q = create();
      talk(p, q);
      Polynom r = create();
      add(p, q, r);
      print(r);

      remove(p);
      remove(q);
      remove(r);
    }
    if (command == compareCode)
    {
      Polynom p = create();
      Polynom q = create();
      talk(p, q);
      if (areEqual(p, q))
        puts("These polynoms are equal");
      else
        puts("These polynoms are not equal");

      remove(p);
      remove(q);
    }

    talkToUser();
    scanf("%d", &command);
  }


  return 0;
}