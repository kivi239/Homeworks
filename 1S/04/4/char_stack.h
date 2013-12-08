namespace CharStacks
{
  struct CharStackElement
  {
    char value;
    CharStackElement *next;
  };
  
  struct CharStack
  {
    CharStackElement *head;
  };

  CharStack create();
  void push(CharStack &, char);
  char pop(CharStack &);
  char top(CharStack &);
  bool isEmpty(CharStack &);
}