#include "graph.h"
#include <cassert>

Graph::Graph(int V, std::vector<std::vector<int> > graph, std::vector<bool> robots) : V(V), g(graph), robotsAt(robots)
{
  was = new bool[V];
  for (int i = 0; i < V; i++)
    was[i] = false;
  assert(V == (int)robots.size() && V == (int)graph.size());
}

Graph::~Graph()
{
  for (int i = 0; i < V; i++)
    g[i].clear();
  g.clear();
  robotsAt.clear();
  delete[] was;
}

bool Graph::canDestroy()
{
  for (int i = 0; i < V; i++)
  {
    if (!robotsAt[i] || was[i])
      continue;
    if (dfs(i) == 1)
      return false;
  }
  return true;
}

int Graph::dfs(int v)
{
  if (was[v])
    return 0;
  was[v] = true;
  int ans = 0;
  if (robotsAt[v])
    ans++;

  for (int j = 0; j < (int)g[v].size(); j++)
    for (int k = 0; k < (int)g[g[v][j]].size(); k++)
      if (!was[g[g[v][j]][k]])
        ans += dfs(g[g[v][j]][k]);
  return ans;
}
