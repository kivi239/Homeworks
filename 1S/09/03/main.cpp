#include <cstdio>
#include "edges.h"

using namespace Edges;

int findRoot(int x, int *root)
{
  if (x != root[x])
    root[x] = findRoot(root[x], root);
  return root[x];
}

void unionOfVertices(int x, int y, int *root, int *rank)
{
  x = findRoot(x, root);
  y = findRoot(y, root);
  if (x == y)
    return;

  if (rank[x] > rank[y])
    root[y] = x;
  else if (rank[x] == rank[y])
  {
    root[y] = x;
    rank[x]++;
  }
  else
    root[x] = y;
}

int main()
{
  freopen("graph.in", "r", stdin);

  int n = 0;
  scanf("%d", &n);
  int **graph = new int*[n];
  for (int i = 0; i < n; i++)
    graph[i] = new int[n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      graph[i][j] = -1;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &graph[i][j]);

  int *root = new int[n];
  int *rank = new int[n];
  for (int i = 0; i < n; i++)
  {
    root[i] = i;
    rank[i] = 1;
  }

  int m = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      m += (graph[i][j] > 0);

  Edge *allEdges = new Edge[m];                                                     
  m = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (graph[i][j] > 0)
        allEdges[m++] = Edge(i, j, graph[i][j]);
  
  quickSort(allEdges, 0, m - 1);
  
  Edge *treeEdges = new Edge[m];
  for (int i = 0; i < m; i++)
    treeEdges[i] = Edge(-1, -1, -1);
  int edgesInTree = 0;

  treeEdges[edgesInTree++] = allEdges[0];
  unionOfVertices(allEdges[0].v, allEdges[0].u, root, rank);
  
  int rt = findRoot(allEdges[0].v, root);
  
  for (int i = 1; i < m; i++)
  {
    Edge curEdge = allEdges[i];
    if (!(findRoot(curEdge.u, root) == findRoot(rt, root) && findRoot(curEdge.v, root) == findRoot(rt, root)))
    {
      treeEdges[edgesInTree++] = curEdge;
      unionOfVertices(rt, curEdge.v, root, rank);
      unionOfVertices(rt, curEdge.u, root, rank);
      rt = findRoot(rt, root);
    }
  }

  printf("Edges in minimum spanning tree are between vertices\n");
  for (int i = 0; i < edgesInTree; i++)
    printf("%d and %d with length %d\n", treeEdges[i].v + 1, treeEdges[i].u + 1, treeEdges[i].len);


  delete[] allEdges;
  delete[] treeEdges;
  delete[] root;
  delete[] rank;
  for (int i = 0; i < n; i++)
    delete[] graph[i];
  delete[] graph;

  return 0;
}