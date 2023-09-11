#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long LL;

const int max_n=20010;
const int modref=1000000007;

int T,n;
vector<int> adjl[max_n];

bool bp;
bool visited[max_n];
int depth[max_n];
int ncct;

void DFS(int vt)
{
	visited[vt]=true;
	
	int vtnbr;
	for(int i=0; i<adjl[vt].size(); ++i)
	{
		vtnbr=adjl[vt][i];
		if(not visited[vtnbr])
		{
			depth[vtnbr]=depth[vt]+1;
			DFS(vtnbr);
		}
		else if((depth[vtnbr]%2)==(depth[vt]%2))
			bp=false;
	}
}

void msDFS()
{
	ncct=0;
	fill(visited,visited+n,false);
	bp=true;
	
	for(int i=0; i<n; ++i)
	{
		if(not visited[i])
		{
			depth[i]=0;
			DFS(i);
			++ncct;
		}
	}
}

LL e2(LL a)
{
	if(a==0)
		return 1;
	else
	{
		LL t=e2(a/2);
		if(a%2==0)
			return ((t*t)%modref);
		else
			return ((t*t*2)%modref);
	}
}

int main()
{
	scanf("%d",&T);
	
	for(int z=0; z<T; ++z)
	{
		scanf("%d",&n);
		
		for(int i=0; i<n; ++i)
			adjl[i].resize(0);
		int nri,cr;
		for(int i=0; i<n; ++i)
		{
			scanf("%d",&nri);
			for(int j=0; j<nri; ++j)
			{
				scanf("%d",&cr);
				adjl[i].push_back(cr);
				adjl[cr].push_back(i);
			}
		}
		
		msDFS();
		
		if(bp)
			cout<<e2(((LL)(ncct)))<<endl;
		else
			printf("0\n");
	}
	
	return 0;
}