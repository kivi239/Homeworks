#include <cstdio>
#include "graph.h"

using namespace Graphs;

void Graphs::createVertex(int num, GraphVertex &newVertex)
{
  newVertex.num = num;
  newVertex.neighbors = create(); 
}

void Graphs::addEdge(GraphVertex vertexU, GraphVertex vertexV, int len)                                                                        
{
  add(vertexU.neighbors, vertexV.num, len);
  add(vertexV.neighbors, vertexU.num, len);
}
