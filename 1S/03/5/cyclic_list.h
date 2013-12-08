namespace CyclicLists
{
  struct CyclicListElement
  {
    int value;
    CyclicListElement *next;
  };

  struct CyclicList
  {
    CyclicListElement *head;
  };

  CyclicList create(int);
  void remove(CyclicList &, int);
  bool isOneElement(CyclicList &);
  void printTheFirst(CyclicList &);
  int size(CyclicList &);
  void deleteAll(CyclicListElement *);
}
