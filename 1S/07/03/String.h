

namespace Strings
{
  struct Char
  {
    char symbol;
    Char *next;
  };

  struct String
  {
    Char *begin;
    Char *end;
  };

  String create(char *, int);
  void remove(String &);
  String clone(String &);
  void concatenation(String &from, String &to);
  bool areEqual(String &, String &);
  int length(String &);
  bool isEmpty(String &);
  String substr(String &, int, int);
  char* convertToChar(String &);
  void print(String &);
  int hashValue(String &, int);
}