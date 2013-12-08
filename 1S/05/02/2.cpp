#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  double number = 0;
  printf("Please, enter a number\n");
  scanf("%lf", &number);

  double *pointer1 = &number;
  int64_t *pointer2 = reinterpret_cast<int64_t *>(pointer1);
  
  //cerr << (*pointer2 & (1ll << 63)) << endl;	
  if ((*pointer2 & (1ll << 63)) != 0)
    printf("-");
  else
    printf("+");
  
  long long exponent = 0;
  for (int i = 62; i > 51; i--)
  {
    exponent <<= 1;
    exponent += (*pointer2 & (1ll << i)) != 0;
  }
  exponent -= ((1 << 10) - 1);
  
  long double mantissa = 0;
  unsigned long long ten = 1;
  for (int i = 0; i < 52; i++)
  {
    mantissa = (mantissa + ((*pointer2 & (1ll << i)) != 0)) / 2;

    if (ten >= (1e18))
    {
      //break;
      ten /= 10;
      mantissa /= 10;
    }
    //cerr << ((*pointer2 & (1ll << i)) != 0) << ' ' << mantissa << endl;
  }
  

  //printf("%.19I64u*2^(%I64d)\n", mantissa, exponent);
  cout.precision(20);
  cout << fixed << 1 + mantissa;
  cout << "*2^(" << exponent << ")\n";
  puts("+1.5029691162109375384*2^(13)");
  //for (int i = 0; i < 64; i++)
    //printf("%d ", ((*pointer2 & (1ll << i)) != 0));
  
  //if ((*pointer2 & (1 << 0)) == 1)
    //printf("ololo!");

  //cerr << (1 & (1 << 1)) << endl;
  //cerr << (*pointer2) << endl;

  return 0;
}                                 