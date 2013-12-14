namespace Polynoms
{
  struct Monom
  {
    int degree;
    int coeff;
    Monom* next;
  };

  struct Polynom
  {
    Monom* first;
  };

  Polynom create();
  void print(Polynom &);
  void add(Polynom &p, int coeff, int degree);
  void add(Polynom &p, Polynom &q, Polynom &r);
  int value(Polynom &, int);
  bool areEqual(Polynom &, Polynom &);
  void remove(Polynom &);
}
