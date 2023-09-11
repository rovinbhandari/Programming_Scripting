#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <ctime>
#include<fstream>
using namespace std;
vector<int> edges[50000];
int color[20000];
long long int result=1;
void bfs(int g,int n)
{
	
	int dist[n], parent[n], region[n];
	memset(parent, -1, sizeof(parent));
	memset(dist, 999999999, sizeof(dist));
	memset(region, 0, sizeof(region));

	color[g]=1; dist[g]=0; parent[g]=-1;
	queue<int> Q;
	Q.push(g);
	region[g]=1;
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		int a=0, b=0;
		for(int i=0; i< edges[u].size(); i++)
		{
			int v=edges[u][i];
			if(region[v]==1)
				a=1;
			if(region[v]==-1)
				b=1;
			if(color[v]==0)
			{
				
				color[v]=1;
				dist[v]=dist[u]+1;
				parent[v]=u;
				Q.push(v);
				
			}
			color[u]=2;
		}
		if(a==0 && b==0)
		{
			region[u]=1;
			result=(result*2)%1000000007;
		}
		else if(a==1 && b==0)
			region[u]=-1;
		else if(b==1 && a==0)
			region[u]=1;
		else
			result=0;
	}
}
void bfs_main(int n)
{
	result=1;
	memset(color, 0, sizeof(color));
	for(int i=0; i<n; i++)
		if(color[i]==0)
		{
			bfs(i, n);
			i=0;
			continue;
		}
	result=result%1000000007;
	cout << result << endl;
}
	
int main()
{
/*
	time_t start,end;
  	char szInput [256];
  	double dif;
  	time (&start);
        ifstream input("input.txt");
        */
	int t;
//	 input >> t;
			cin>>t;
	while(t--)
	{
		memset(edges, 0, sizeof(edges));
		memset(color, 0, sizeof(color));
		result=1;
		int n; //number of nodes in graph...nodes are numbered from 0 to n-1.
//		input >> n;
			cin>>n;
		int m;
		int a, b;
		for(int i=0; i< n;i++)
		{
		cin>>m;
//			input >> m;
			for(int j=0; j< m; j++)
			{
					cin>>a;
//				input >> a;
				edges[i].push_back(a);
				edges[a].push_back(i);
			}
		}
		bfs_main(n);
	}
	/*
  	time (&end);
  	dif = difftime (end,start);
  	printf ("It took you %.2lf seconds to type your name.\n", dif ); 
  	*/	
	return 0;
}
