#include "list.h"

using namespace Lists;

namespace Graphs
{
  struct GraphVertex
  {
    int num;
    List neighbors;
  };

  void addEdge(GraphVertex vertexU, GraphVertex vertexV, int len);
  void createVertex(int num, GraphVertex &);
}
