#include <cstdio>
#include <cstdlib>
#include <ctime>

const int maxSize = 100500;

struct Frac
{
  int num;
  int dom;
  Frac() {}
  Frac(int _num, int _dom)
  {
    num = _num;
    dom = _dom;
  }
};

bool operator == (Frac a, Frac b) 
{
  return (a.num == b.num && a.dom == b.dom);
}

bool operator < (Frac a, Frac b)
{
  return (a.num * b.dom < a.dom * b.num);
}

void swap(Frac& x, Frac& y)
{ 
  if (x == y)
    return;
  
  Frac tmp = Frac(x.num, x.dom);
  x = y;
  y = tmp;
}

void quickSort(Frac* a, int l, int r)
{
  int i = l;
  int j = r;
  int m = rand() % (r - l + 1) + l;

  while (i <= j) 
  {
    while (a[i] < a[m]) 
      i++;
    while (a[m] < a[j]) 
      j--;

    if (i <= j) 
    {
      swap(a[i], a[j]);
      i++; 
      j--;
    }
  } 

  if (l < j)
    quickSort(a, l, j);
  if (i < r)
    quickSort(a, i, r);
}

int gcd(int a, int b)
{
  if (a == 0 || b == 0)                                                                
    return a + b;
  return gcd(b, a % b);
}

int main()
{
  srand(time(NULL));

  printf("Please, enter an integer n\n");
  int n = 0;
  scanf("%d", &n);

  Frac all[maxSize];
  for (int i = 0; i < maxSize; i++)
    all[i].num = 0, all[i].dom = 0;

  int cnt = 0;

  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
      if (gcd(i, j) == 1)
        all[cnt++] = Frac(j, i);
  
  quickSort(all, 0, cnt - 1);

  for (int i = 0; i < cnt; i++)
    printf("%d/%d\n", all[i].num, all[i].dom);

  return 0;
}
