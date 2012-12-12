#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;

#define MOD 1000000007ll

int n;
vector <vector <int> > adj;

vector <int> visited;
vector <int> parity;

int dfs_n(int r)
{
	// check for odd cycle.
//	cout<<"DFS "<<r<<endl;

	for( int i=0;i<adj[r].size();i++)
	{
		int p = adj[r][i];
		if( parity[p] == parity[r] && visited[p] == 1)
			return 0;
	}

	for( int i=0;i<adj[r].size();i++)
	{
		int p = adj[r][i];
		if( visited[p] == 0 )
		{
			visited[p] = 1;
			parity[p] = (parity[r]+3)%2;
			int temp = dfs_n(p);
			if( temp == 0 )
				return 0;
		}
	}
	return 1;
}


int dfs()
{
	visited.resize(n);
	parity.resize(n);
	for( int i=0;i<n;i++)
	{
		visited[i] = 0;
		parity[i] = 0;
	}

	int com = 0;
	for( int i=0;i<n;i++)
	{
		if( visited[i] == 0 )
		{
		//	cout<<"I "<<i<<endl;
			com++;
			visited[i] = 1;
			parity[i] = 0;
			if( dfs_n(i) == 0)
				return -1;

		}
	}
	return com;
}


long long expo(int com)
{
	if( com == 0 )
		return 1;
	long long t = expo(com/2);
	t = (t*t+MOD);
	t %= MOD;
	if( com%2 == 1 )
	{
		t = (t*2 + MOD);
		t %= MOD;
	}
	return t;
}


int main()
{
	int t;
	cin>>t;
	while( t-- )
	{
		scanf("%d", &n);
		adj.resize(n);
		for( int i=0;i<n;i++)
		{
			int k;
			scanf("%d", &k);
			for( int j=0;j<k;j++)
			{
				int tt;
				scanf("%d", &tt);
				adj[i].push_back(tt);
				adj[tt].push_back(i);
			}
		}
		int com = dfs();
		//cout<<com<<endl;
		if( com == -1 )
			cout<<"0"<<endl;
		else
			cout<<expo(com)<<endl;

		for( int i=0;i<n;i++)
			adj[i].clear();
		adj.clear();
	}

	
	return 0;
}

			
	

