namespace Lists
{
  struct ListElement
  {
    int vertex;
    int length;
    ListElement *next;
  };

  struct List
  {
    ListElement *head;
  };
  
  List create();
  void add(List &, int, int);
  void print(List &);
  void deleteAll(ListElement *);
  int size(List &);
}
