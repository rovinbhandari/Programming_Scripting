/*
	Rovin Bhandari
	11/10/2011
	
	COINS
*/

#include <cstdio>
#include <map>
using std::map;

#define MEMARRSIZE 40000000
#define MAX(a, b) ((a > b) ? a : b)

map<int, unsigned int> memo;	// memoization hash table consisting of number as hash-key and the number's equivalent max$ value as hash-value
map<int, unsigned int>::iterator i;
unsigned int memarr[MEMARRSIZE];

void buildmemarr()
{
	memarr[0] = 0u;
	for(int j = 1; j < MEMARRSIZE; j++)
		memarr[j] = MAX(j, memarr[j >> 2] + memarr[j / 3] + memarr[j >> 1]);
}

unsigned int max$(int x)
{
	if(x == 0)
		return 0;
	else if(x < MEMARRSIZE)
		return memarr[x];
	else if((i = memo.find(x)) != memo.end())
		return i->second;
	else
		return memo[x] = MAX(x, max$(x >> 2) + max$(x / 3) + max$(x >> 1));
}

int main()
{
	buildmemarr();
	int n;
	while(scanf("%d", &n) > 0)
		printf("%u\n", max$(n));
	return 0;
}
