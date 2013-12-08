#include <cstdio>
#include "graph.h"

using namespace Graphs;

const int inf = (int)(2e9);

void Dijkstra(int n, GraphVertex *graph)
{
  int *dist = new int[n];
  int *from = new int[n];
  bool *was = new bool[n];
  int *path = new int[n];

  for (int i = 0; i < n; i++)
  {
    dist[i] = inf;
    from[i] = -1;
    was[i] = false;
  }
  dist[0] = 0;
  was[0] = true;

  while (1)
  {
    int curId = -1;
    for (int i = 0; i < n; i++)
    {
      if (was[i] && (curId == -1 || dist[i] < dist[curId]))
        curId = i;
    }

    if (curId == -1)
      break;

    if (curId != 0)
    {
      printf("%d: %d, ", curId + 1, dist[curId]);
      
      int vertex = curId;
      int k = 0;
      while (vertex != 0)
      {
        path[k++] = vertex;                                                                                                       
        vertex = from[vertex];
      }
      path[k++] = 0;

      for (int i = k - 1; i >= 0; i--)
        printf("%d ", path[i] + 1);
      puts("");
    }

    int countOfNeighbors = size(graph[curId].neighbors);
    ListElement *curElement = graph[curId].neighbors.head;
    for (int i = 0; i < countOfNeighbors; i++)
    {
      curElement = curElement->next;
      if (dist[curElement->vertex] > dist[curId] + curElement->length)
      {
        dist[curElement->vertex] = dist[curId] + curElement->length;
        from[curElement->vertex] = curId;
        was[curElement->vertex] = true;
      }
    }
    was[curId] = false;
  }

  delete[] dist;
  delete[] from;
  delete[] was;
  delete[] path;
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
    int length = 0;
    scanf("%d%d%d", &u, &v, &length);
    u--;
    v--;
    addEdge(graph[u], graph[v], length);
  }

  Dijkstra(n, graph);

  for (int i = 0; i < n; i++)
    deleteAll(graph[i].neighbors.head);

  delete[] graph;
  
  return 0;
}