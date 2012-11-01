#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF	1000000000

int* apspl = NULL;	// apspl : all-pair shortest path lengths
unsigned int n = 0, m = 0, q = 0;

struct edge
{
	int u;
	int v;
	int w;
};

edge* edges = NULL;

void init(void)
{
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i == j)
				apspl[i * n + j] = 0;
			else
				apspl[i * n + j] = INF;
}

void FloydWarshall(void)
{
	int i, j, k;
	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(apspl[i * n + k] + apspl[k * n + j] < apspl[i * n + j])
					apspl[i * n + j] = apspl[i * n + k] + apspl[k * n + j];
}

void FWservequeries()
{
	int a, b, i = 0;
	while(i < q)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", apspl[a * n + b]);
		i++;
	}
}

void BellmanFord(int* ssspl, int s)
{
	int i, j;
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < m; j++)
			if(ssspl[edges[j].u] + edges[j].w < ssspl[edges[j].v])
				ssspl[edges[j].v] = ssspl[edges[j].u] + edges[j].w;
}

void BFservequeries(bool* iscached)
{
	int i = 0, j, s, t;
	while(i < q)
	{
		scanf("%d", &s);
		scanf("%d", &t);
		if(iscached[s])
			printf("%d\n", apspl[s * n + t]);
		else
		{
			int* ssspl = (int*) malloc(sizeof(int) * n);
			for(j = 0; j < n; j++)
				ssspl[j] = INF;
			ssspl[s] = 0;
			BellmanFord(ssspl, s); 
			memcpy(&apspl[s * n], ssspl, n * sizeof(int));
			iscached[s] = true;
			printf("%d\n", ssspl[t]);
			//free(ssspl);
		}
		i++;
	}
}

int main(void)
{
	int t, a, b, w;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		apspl = (int*) malloc(sizeof(int) * n * n);
		init();
		scanf("%d", &m);
		edges = (edge*) malloc(sizeof(edge) * m);
		int i = m;
		while(i--)
		{
			scanf("%d", &a);
			scanf("%d", &b);
			scanf("%d", &w);
			if(w < apspl[a * n + b])
				apspl[a * n + b] = w;
			edges[i].u = a;
			edges[i].v = b;
			edges[i].w = w;
		}
		scanf("%d", &q);
		if(q * m >= n * n)
		{
			FloydWarshall();
			FWservequeries();
		}
		else
		{
			bool* iscached = (bool*) calloc(m, sizeof(bool));
			BFservequeries(iscached);
			//free(iscached);
		}
		//free(apspl);
		//free(edges);
	}
}

