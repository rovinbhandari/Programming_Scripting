#include <climits>
#include <vector>
#include <cstdio>
using namespace std;

/*
	* create a graph of attacks (g) in which an edge represents a relation \
	  "has more power".
	* define an edge between a and b (a-->b) if b has more power than a.
	* G can win with score 2 if g has a vertex with no outdegree.
	* G can lose with score 0 if g has no vertex with outdegree 0 but there \
	  exists a DFT of length exactly 2.
	* G can win with score 1 if g has no vertex with oudegree 0, no DFT of \
	  length exactly 2 but there exists a DFT of length 3 or more.
	*
	* observe that in this problem, a DFT of length exactly 2 is not \
	  possible. therefore, either we have a vertex with outdegree 0 \
	  (observe that this vertex would be unique) or we can output 1 \
	  straightaway.
*/

int main(void)
{
	int t, n, m, a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		vector<int> outdegrees(n + 1, 0);
		for(int i = 1; i <= n; i++)
			outdegrees[i] = n - i;
		scanf("%d", &m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d", &a);
			scanf("%d", &b);
			// make sure a is less than b before modifying oudegrees.
			if(a > b)
			{
				int tmp = a;
				a = b;
				b = tmp;
			}
			// a's indegree increases by 1; b's outdegree increases by 1.
			outdegrees[a]--;
			outdegrees[b]++;
		}
		int minoutdegree = INT_MAX, minoutdegreevertex = -1;
		for(int i = 1; i <= n; i++)
		{
			if(minoutdegree > outdegrees[i])
			{
				minoutdegree = outdegrees[i];
				minoutdegreevertex = i;
			}
		}
		if(minoutdegree == 0)
			printf("2 %d\n", minoutdegreevertex);
		else
			printf("1\n");
	}
	return 0;
}
