// Implementation of 0,1 network flow \
   using Edmonds-Karp algorithm.
#include <cstdio>
#include <vector>
#include <climits>
#include <cfloat>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int n;

//capacity
double* capacity;
//residual capacity
double* rcapacity;
#define MAP(i, j)	(i * (n + 1) + j)

//edgelist
vector<vector<int> > edgelist;

double EdmondsKarp(int s, int t)
{
	cerr<<edgelist.size()
		<<endl;
	while(true)
	{
		vector<int> P(n + 1, -1);
		P[s] = s;
		double* M = (double*) calloc((n + 1), sizeof(double));
		M[s] = DBL_MAX;
		queue<int> Q;
		Q.push(s);
		bool exitSecondloop = false;
		while(!Q.empty() && !exitSecondloop)
		{
			int u = Q.front();
			Q.pop();
			for(vector<int>::iterator itv = edgelist[u].begin();
					itv != edgelist[u].end() && !exitSecondloop; itv++)
			{
				int v = *itv;
				if(capacity[MAP(u, v)] - rcapacity[MAP(u, v)] > 0
						&& P[v] == -1)
				{
					P[v] = u;
					M[v] = min(M[u], capacity[MAP(u, v)] - rcapacity[MAP(u, v)]);
					if(v != t)
						Q.push(v);
					else
					{
						while(P[v] != v)
						{
							u = P[v];
							rcapacity[MAP(u, v)] += M[t];
							rcapacity[MAP(v, u)] -= M[t];
							v = u;
						}
						exitSecondloop = true;
					}
				}
			}
		}
		// add code to handle the situation if no path from s to t \
		   could be found.
		cerr<<P[t]<<endl;
		if(P[t] == -1)
		{
			double sum = 0;
			for(int i = 1; i <= n; i++)
				sum += rcapacity[MAP(s, i)];
			return sum;
		}
	}
}

int main(void)
{
	int t;
	int u, v;
	double s;
	scanf ("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		edgelist = vector<vector<int> >(n + 1);
	
		capacity = (double*) calloc((n + 1) * (n + 1), sizeof(double));
		rcapacity = (double*) calloc((n + 1) * (n + 1), sizeof(double));

		while(true)
		{
			scanf("%d", &u);
			scanf("%d", &v);
			scanf("%lf", &s);
			if(u == -1 && v == -1)
				break;
			//store
			capacity[MAP(u, v)] = s;
			edgelist[u].push_back(v);
		}

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				cerr << capacity[MAP(i, j)]
					 << " ";
			cerr << endl;
		}
		
		printf("%f\n", EdmondsKarp(n, 1));

		//TODO: free capacity and edgelist
	}
	return 0;
}
