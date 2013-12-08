#include <cstdio>

int main()
{
  printf("Please, enter an integer number n\n");
  int n;
  scanf("%d", &n);
  printf("Please, enter the two-dimensional array of size n * n\n");
  
  int **arr = new int*[n];
  for (int i = 0; i < n; i++)
    	arr[i] = new int[n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &arr[i][j]);                                                                                  

  int curI = n / 2;
  int curJ = n / 2;
  printf("%d ", arr[curI][curJ]);
  //printf("(%d, %d)\n", curI, curJ);
  for (int step = 1; step < n; step++)
  {
    for (int i = 0; i < step; i++)
    {
      curI--;
      printf("%d ", arr[curI][curJ]);
    }
    for (int i = 0; i < step; i++)
    {
      curJ++;
      printf("%d ", arr[curI][curJ]);
    }
    step++;
    for (int i = 0; i < step; i++)
    {
      curI++;
      printf("%d ", arr[curI][curJ]);
    }
    for (int i = 0; i < step; i++)
    {
      curJ--;
      printf("%d ", arr[curI][curJ]);
    }
  }
  
  for (int i = 0; i < n - 1; i++)
  {
    curI--;
    printf("%d ", arr[curI][curJ]);
  }

  for (int i = 0; i < n; i++)
    delete[] arr[i];

  delete[] arr;

  return 0;
}                                            