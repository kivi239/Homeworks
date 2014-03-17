#include "console_outputer.h"
#include "file_outputer.h"
#include <cstdio>

int main()
{
  printf("Please, enter n\n");
  int n = 0;
  scanf("%d", &n);
  int **a = new int*[n];
  
  for (int i = 0; i < n; i++)
    a[i] = new int[n];
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = 0;

  printf("Please, enter the matrix of size n * n\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &a[i][j]); 

  Outputer *console = new ConsoleOutputer();
  Outputer *file = new FileOutputer();
  console->out(a, n);
  file->out(a, n);

  delete console;
  delete file;
  for (int i = 0; i < n; i++)
    delete[] a[i];
  delete[] a;

  return 0;
}
