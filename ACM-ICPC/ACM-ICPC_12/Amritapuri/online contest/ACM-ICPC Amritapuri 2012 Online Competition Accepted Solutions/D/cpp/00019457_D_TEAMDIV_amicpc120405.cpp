#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


class Graph
{
public:
  vector < list <int> > adjacencyList;
  vector <bool> vertices;
  // map < pair<int,int>, int > Kanpur,Amritapuri;
  int numVertices;
  // int min(int num1,int num2);
  // void printPrivate(vector <list <int> > adjacencyList);
  Graph(int input1);
  void readEdges();
  // void print();
  // void dfs(int vertex);
  bool bfs(int vertex);
  // int shortestLength(int vertex1,int vertex2);
};

Graph::Graph(int input1)
{
  numVertices = input1;
  adjacencyList.resize(numVertices);
  vertices.resize(numVertices);
}

void Graph::readEdges()
{
  for (int i=0; i < numVertices; ++i)
    {
      int numEdges;
      cin >> numEdges;
      for (int j=0; j < numEdges; ++j)
	{
	  int vertex;
	  cin >> vertex;
	  adjacencyList[i].push_back(vertex);
	  adjacencyList[vertex].push_back(i);
	}
    }
}



bool Graph::bfs(int vertex)
{
  vector <bool> partition(numVertices,0);
  queue < pair <int,int> > levels;
  levels.push(pair <int,int> (vertex,0));
  int i=0;
  while (!levels.empty())
    {
      int currentVertex = levels.front().first;
      int currentLevel = levels.front().second;
      bool levelEnd = true;
      levels.pop();
      if (!levels.empty())
	{
	  int nextLevel = levels.front().second;
	  if (nextLevel == currentLevel)
	    levelEnd = false;
	}
      if (vertices[currentVertex] == false)
	{
	  partition[currentVertex] = i%2;
	  vertices[currentVertex] = true;
	}
      for (list <int>::iterator lx = adjacencyList[currentVertex].begin(); lx != adjacencyList[currentVertex].end(); ++lx)
	{
	  if (vertices[*lx] == true)
	    {
	      if (partition[*lx] != (i+1)%2)
		return false;
	      continue;
	    }
	  partition[*lx] = (i+1)%2;
	  vertices[*lx] = true;
	  levels.push(pair <int,int> (*lx,(i+1)%2));
	}
      if (levelEnd == true)
	++i;
    }
  return true;
}


main()
{
  int numTestCases;
  cin >> numTestCases;
  for (int i=0; i<numTestCases; ++i)
    {
      int numTeams;
      cin >> numTeams;
      Graph G(numTeams);
      G.readEdges();
      bool check = true;
      int count = 1;
      for (int i=0; i<G.numVertices; ++i)
	{
	  if (G.vertices[i] == false)
	    {
	      check = G.bfs(i);
	      if ( check == false)
		{
		  cout << 0 << endl;
		  break;
		}
	      count = (count*2)%(1000000007);
	    }
	}
      if (check == true)
	cout << count << endl;
    }
}
