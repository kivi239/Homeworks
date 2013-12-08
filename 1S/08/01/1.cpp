#include <cstdio>                                                                                  

const int maxFile = 100;
const int maxVertex = 27;

int countOfNeighbors[maxVertex];
int neighbors[maxVertex][maxVertex];

void dfs(int curV, char &curLetter, bool *was, char *answer, int neighbors[27][27])
{
  was[curV] = true;
  answer[curV] = curLetter;
  for (int i = 0; i < countOfNeighbors[curV]; i++)
  {
    if (!was[neighbors[curV][i]])
    {
      curLetter++;
      dfs(neighbors[curV][i], curLetter, was, answer, neighbors);
    }
  } 
}

int main()
{
  puts("Please, enter a name of file and number of starting vertex\n");
  int start = -1;                                                                                                                   
  char nameOfFile[maxFile];
  for (int i = 0; i < maxFile; i++)
    nameOfFile[i] = '\0'; 
  
  scanf("%s", nameOfFile);
  scanf("%d", &start);

  freopen(nameOfFile, "r", stdin);
                                                                                                                    
  int neighbors[27][27];
  int u = -1;
  int v = -1;
  for (int i = 0; i < maxVertex; i++)
    for (int j = 0; j < maxVertex; j++)
      neighbors[i][j] = -1;
  
  while (scanf("%d%d", &u, &v) > 0)
  {
    if (u > 26)
    {
      puts("There is too many vertices!\n");
      return 0;
    }

    neighbors[u][countOfNeighbors[u]] = v;
    neighbors[v][countOfNeighbors[v]] = u;
    countOfNeighbors[u]++;
    countOfNeighbors[v]++;
  }

  bool was[maxVertex];
  for (int i = 0; i < maxVertex; i++)
    was[i] = false;

  char answer[maxVertex];
  for (int i = 0; i < maxVertex; i++)
    answer[i] = '?';

  char first = 'a';
  dfs(start, first, was, answer, neighbors);

  for (int i = 0; i < maxVertex; i++)
    if (answer[i] != '?')
      printf("%d is %c\n", i, answer[i]);

  return 0;
}             
