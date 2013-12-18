#include <cstdio>
#include "tree.h"

using namespace Trees;

int main()
{
  FILE *archive = fopen("archive.txt", "rt");
  FILE *file = fopen("file.txt", "wt");
  char c = '\0';
  fread(&c, sizeof(char), 1, archive);
  Tree t = build(archive);
  fread(&c, sizeof(char), 1, archive);

  printString(t, archive, file);
  
  remove(t);
  fclose(archive);

  return 0;
}