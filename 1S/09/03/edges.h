namespace Edges
{
  struct Edge
  {
    int v;
    int u;
    int len;
    Edge() {};
    Edge(int _v, int _u, int _len)
    {
      v = _v;
      u = _u;
      len = _len;
    }
  };
  bool operator < (Edge edge1, Edge edge2);
  bool operator > (Edge edge1, Edge edge2);
  void quickSort(Edge *, int, int);
}