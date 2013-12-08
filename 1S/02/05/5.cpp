#include <cstdio>

const int maxSize = 100500;

void swap(int& a, int& b)
{
  if (a == b)
    return;
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

void push(int id, int size, int* a)
{
  if (2 * id + 1 >= size)
    return;

  int idMin = id;
  if (2 * id + 1 < size && a[id] > a[2 * id + 1])
    idMin = 2 * id + 1;
  if (2 * id + 2 < size && a[idMin] > a[2 * id + 2])
    idMin = 2 * id + 2;

  if (idMin == id)
    return;
  swap(a[id], a[idMin]);
  push(idMin, size, a);
}

int main()
{
  printf("Please, enter integer n\n");
  int n;
  scanf("%d", &n);
  printf("Please, enter the array of size n\n");
  int heap[maxSize];

  for (int i = 0; i < maxSize; i++)
    heap[i] = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", &heap[i]);

  int size = n;
  for (int i = size / 2 - 1; i >= 0; i--)
    push(i, size, heap);

  while (size > 0)
  {
    printf("%d ", heap[0]);
    swap(heap[0], heap[size - 1]);
    size--;
    push(0, size, heap);
  }

  return 0;
}