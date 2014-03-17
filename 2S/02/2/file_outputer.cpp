#include "file_outputer.h"
#include <cstdio>

FileOutputer::~FileOutputer() {}

void FileOutputer::out(int **a, int n)
{
  FILE *file = fopen("file.txt", "wt");
  int *arr = output(a, n);
  for (int i = 0; i < n * n; i++)
    fprintf(file, "%d ", arr[i]);

  delete[] arr;
  fclose(file);
}
