#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
public:
  /**
   * @brief Graph main constructor for Graph class
   * @param V count of vertices in graph
   * @param graph adjacency list (must be symmetrical for non-oriented graph!)
   * @param robots initial position of robots
   */
  Graph(int V, std::vector<std::vector<int> > graph, std::vector<bool> robots);
  ~Graph();

  /**
   * @brief canDestroy show is it possible to destroy all of robots
   * @return is it possible
   */
  bool canDestroy();

private:
  int dfs(int v);
  int V;
  std::vector<std::vector<int> > g;
  std::vector<bool> robotsAt;
  bool *was;
};

#endif // GRAPH_H
