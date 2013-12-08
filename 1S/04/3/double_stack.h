namespace DoubleStacks
{
  struct DoubleStackElement
  {
    double value;
    DoubleStackElement *next;
  };
  
  struct DoubleStack
  {
    DoubleStackElement *head;
  };

  DoubleStack create();
  void push(DoubleStack &, double);
  double pop(DoubleStack &);
  double top(DoubleStack &);
  int size(DoubleStack &);
}