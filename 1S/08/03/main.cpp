#include <cstdio>
#include "graph.h"

using namespace Graphs;

void dfs(int v, int n, bool *was, GraphVertex *graph)
{
  was[v] = true;
  printf("%d ", v + 1);
  int countOfNeighbors = size(graph[v].neighbors);
  
  ListElement *curElement = graph[v].neighbors.head;
  for (int i = 0; i < countOfNeighbors; i++)
  {
    curElement = curElement->next;
    if (!was[curElement->vertex])
      dfs(curElement->vertex, n, was, graph);
  }
}

int main()
{

  freopen("graph.in", "r", stdin); 
  int n = 0;
  int m = 0;
  scanf("%d%d", &n, &m); 

  GraphVertex *graph = new GraphVertex[n];

  for (int i = 0; i < n; i++)
    createVertex(i, graph[i]);

  for (int i = 0; i < m; i++)
  {
    int u = 0;
    int v = 0;
    scanf("%d%d", &u, &v);
    u--;
    v--;

    addEdge(graph[u], graph[v], 1);
  }
  
  bool *was = new bool[n];
  for (int i = 0; i < n; i++)
    was[i] = false;

  for (int i = 0; i < n; i++)
    if (!was[i])
    {
      dfs(i, n, was, graph);
      puts("");
    }

  for (int i = 0; i < n; i++)
    deleteAll(graph[i].neighbors.head);

  delete[] graph;
  delete[] was;

  return 0;
}             