#include "edges.h"
#include <algorithm>

using namespace Edges;

void swap(Edge &x, Edge &y)
{ 
  Edge temp = Edge(x);
  x = y;
  y = temp;
}

bool Edges::operator < (Edge edge1, Edge edge2)
{
  return edge1.len < edge2.len;
}
bool Edges::operator > (Edge edge1, Edge edge2)
{
  return edge1.len > edge2.len;
}

void Edges::quickSort(Edge* a, int l, int r)
{
  int i = l;
  int j = r;
  int m = rand() % (r - l + 1) + l;

  while (i <= j) 
  {
    while (a[i] < a[m]) 
      i++;
    while (a[j] > a[m]) 
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
