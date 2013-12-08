#include <cstdio>
#include <cstring>

const int maxLen = 1000;

int main()
{
  FILE *cpp = fopen("file.cpp", "rt");
  char curLine[maxLen];
  
  bool bigComment = false;
  bool openQuote = false;
  bool comment = false;

  while (fgets(curLine, maxLen, cpp))
  {
    int lenOfLine = strlen(curLine);
    comment = false;
    for (int i = 0; i < lenOfLine; i++)
    {
      if (comment)
      {
        printf("%c", curLine[i]);
        continue;
      }

      if (curLine[i] == '"')
      {
        if (bigComment)
          continue;
        if ((openQuote && i != 0 && curLine[i - 1] != '\\') || !openQuote || (openQuote && i == 0))
          openQuote = !openQuote;
      }
      else if (curLine[i] == '/' && i != lenOfLine - 1 && curLine[i + 1] == '*')
      {
        if (!openQuote)
          bigComment = true;
      }
      else if (curLine[i] == '*' && i != lenOfLine - 1 && curLine[i + 1] == '/')
      {
        if (!openQuote)
          bigComment = false;
      }
      else if (curLine[i] == '/' && i != lenOfLine - 1 && curLine[i + 1] == '/')
      {
        if (!openQuote && !bigComment)
        {
          printf("/");
          comment = true;
        }
      }
    }
  }

  fclose(cpp);                    
  
  return 0;
}
