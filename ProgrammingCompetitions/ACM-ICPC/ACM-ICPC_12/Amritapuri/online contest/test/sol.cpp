#include <cstdio>
#include <queue>
#include <strings.h>

#define MOD_N 1000000007

typedef long long unsigned int llui;

using namespace std;
int **adjacencyMatrix;

llui computePower (int& n)
{
  llui ans = 2;
  for (; n > 1; n--)
  {
    ans <<= 1;
    ans %= MOD_N;
  }
  return ans;
}

enum {RED = 1, BLUE};

int nSCC (int n)
{
  queue<int> q;
  int nComponents = 0;
  int visited[n];
  int color[n];
  bzero (color, sizeof(int) * n);
  bzero (visited, sizeof(int) * n);
  
  for (int i = 0; i < n; i++)
  {
    if (visited[i])
      continue;
    
    //color[i] = RED;
    
    /* BFS starting with vertex i as root. */
    q.push(i);
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      for (int j = 0; j < n; j++)
      {
        if (adjacencyMatrix[v][j] == 1)
        {
          q.push(j);
	  printf("vertex pushed is %d\n",j);
          adjacencyMatrix[v][j] = adjacencyMatrix[j][v] = -1;
          //color[j] =  (color[v] == RED) ? BLUE : RED;
        }
        /*else if (adjacencyMatrix[v][j] == -1 && color[j] == color[v])
        {
          return -1;
        }*/
      }
      visited[v] = 1;
    }
    /* BFS starting with vertex i as root. */
    
    nComponents++;
  }

  return nComponents;
}

int main (void)
{
  int t, n, tmp, nComponents;
  scanf ("%d", &t);
  
  while (t--)
  {
    scanf ("%d", &n);
    adjacencyMatrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
      adjacencyMatrix[i] = new int[n];
      for (int j = 0; j < n; j++)
        adjacencyMatrix[i][j] = 0;
    }
    int nRivals, rival;
    for (int i = 0; i < n; i++)
    {
      scanf ("%d", &nRivals);
      while (nRivals--)
      {
        scanf ("%d", &rival);
        adjacencyMatrix[i][rival] = adjacencyMatrix[rival][i] = 1;
      }
    }

    nComponents = nSCC(n);
    if (nComponents > 0)
      printf ("%llu\n", computePower (nComponents));
    else
      printf ("0\n");
  }
  return 0;
}
