#include <cstdio>
#include <cstring>

const int alph = 26;

int main()
{
  int cnt1[alph];
  int cnt2[alph];

  for (int i = 0; i < alph; i++)
  {
    cnt1[i] = 0;
    cnt2[i] = 0;
  }
  
  printf("Please, enter an integer number n\n");
  int n;
  scanf("%d", &n);
  printf("Please, enter two strings of size n\n");                                           
  char *str1 = new char[n];
  scanf("%s", str1);
  char *str2 = new char[n];
  scanf("%s", str2);

  for (int i = 0; i < n; i++)
  {
    cnt1[str1[i] - 'a']++;
    cnt2[str2[i] - 'a']++;
  }

  delete[] str1;
  delete[] str2;
  
  bool isequal = true;

  for (int i = 0; i < alph; i++)
    if (cnt1[i] != cnt2[i])
      isequal = false;

  if (isequal)
    printf("It is possible to transpose symbols in the second string and get the first string\n");
  else
    printf("It is impossible to transpose symbols in the second string and get the first string\n");

  return 0;                                                                                         
}      