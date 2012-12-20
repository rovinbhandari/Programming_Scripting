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

const int max_n=50010;
const int max_m=50010;

int T,n,m;

LL stick[max_n];
LL box[max_m];

LL sq(int a) { return ((LL)(a))*((LL)(a)); }

int main()
{
	scanf("%d",&T);
	
	for(int z=0; z<T; ++z)
	{
		scanf("%d%d",&n,&m);
		
		int t1,t2,t3;
		for(int i=0; i<n; ++i)
		{
			scanf("%d",&t1);
			stick[i]=sq(t1);
		}
		
		for(int i=0; i<m; ++i)
		{
			scanf("%d%d%d",&t1,&t2,&t3);
			box[i]=sq(t1)+sq(t2)+sq(t3);
		}
		
		sort(stick,stick+n);
		sort(box,box+m);
		
		int res=0;
		for(int i=0; i<n; ++i)
		{
			if(stick[i]<=box[m-1])
				++res;
		}
		
		printf("%d\n",res);
	}
	
	return 0;
}