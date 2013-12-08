#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxSize = 100;

void division(int *longInt, bool plusOne)
{
  for (int i = 0; i < maxSize - 1; i++)
  {
    longInt[i + 1] += (longInt[i] % 2 * 10);
    longInt[i] /= 2;
  }
  
  if (plusOne)
    longInt[0] += 5;
}

void print(int *longInt)
{
  int curId = maxSize - 1;
  while (curId >= 0 && longInt[curId] == 0)
    curId--;
  if (curId < 0)
  {
    printf("0");
    return;
  }
  int lastId = curId;
  for (int i = 0; i <= lastId; i++)
    printf("%d", longInt[i]);
}

int main()
{
  double number = 0;
  printf("Please, enter a number\n");
  scanf("%lf", &number);

  double *pointer1 = &number;
  int64_t *pointer2 = reinterpret_cast<int64_t *>(pointer1);
  
  if ((*pointer2 & (1ll << 63)) != 0)
    printf("-");
  else
    printf("+");

  bool isNull = true;
  for (int i = 0; i < 63; i++)
    isNull &= (*pointer2 & (1ll << i)) == 0;
  
  if (isNull)
  {
    puts("0.0*2^0");
    return 0;
  }

  printf("1.");
                                                                  
  long long exponent = 0;
  for (int i = 62; i > 51; i--)
  {
    exponent <<= 1;
    exponent += (*pointer2 & (1ll << i)) != 0;
  }
  exponent -= ((1 << 10) - 1);
  
  int mantissa[maxSize];
  for (int i = 0; i < maxSize; i++)
    mantissa[i] = 0;
  
  for (int i = 0; i < 52; i++)
    division(mantissa, ((*pointer2 & (1ll << i)) != 0));
  
  print(mantissa);
  printf("*2^(%lld)\n", exponent);

  return 0;
}
                                