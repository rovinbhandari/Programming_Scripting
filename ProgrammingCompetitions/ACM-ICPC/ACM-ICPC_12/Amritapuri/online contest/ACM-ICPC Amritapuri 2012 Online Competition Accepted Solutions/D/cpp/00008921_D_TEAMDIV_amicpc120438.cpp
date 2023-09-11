#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

#define modp 1000000007
int visited[20000];
int color[20000];
class Graph
{
	int V;	// No. of vertices
	vector<int> *adj;	// Pointer to an array containing adjacency lists
	map<int, map<int, bool> > edge_Check;
	public:
	Graph(int V);	// Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	int BFS(int s);	// prints BFS traversal from a given source s
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
	if(edge_Check[v][w] == 0){
		edge_Check[v][w] = 1;
		edge_Check[w][v] = 1;
		adj[v].push_back(w);
		adj[w].push_back(v);
	}
}

int Graph::BFS(int s)
{
	
	queue<int> qu;
	visited[s] = true;
	color[s] = 0;
	qu.push(s);
	vector<int>::iterator it;
	
	while(!qu.empty())
	{

		s = qu.front();
		qu.pop();
		for(it = adj[s].begin(); it != adj[s].end(); ++it)
		{
			if(!visited[*it])
			{
				visited[*it] = 1;
				color[*it] = (color[s] + 1)%2;
				qu.push(*it);
			}
			else{
				if(color[*it]==color[s]) return 1;
			}
		}
	}
	return 0;
}

long long modpower(long long n){
	if(n == 0) return 1;
	else if(n%2 == 0){
		long long p = modpower(n/2);
		p = (p*p)% modp;
		return p;
	}
	else{
		long long p = modpower(n-1);
		p = (p*2) % modp;
		return p;
	} 
}

int main(){
	int t;
	cin>>t;
	int n;
	while(t--){
		scanf("%d",&n);
		Graph g(n);

		int k,v;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&k);
			visited[i] = 0;
			for(int j = 0;j<k;j++){
				scanf("%d",&v);
				g.addEdge(i,v);
			}
		}
		long long count = 0;
		for (int i = 0; i < n; ++i)
		{
			if(!visited[i]) {
				int l = g.BFS(i);
				if(l == 1) {
					count = -1;
					break;
				}
				count++;
			}	
		}
		if(count >= 0) cout<<modpower(count)<<endl;
		else cout<<0<<endl;
	}
	return 0;
}