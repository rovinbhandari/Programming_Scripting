#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctime>

using namespace std;

long long int l[50009];
int a[50009];
int b[50009];
int c[50009];
long long int d[50009];

bool myfun(const long long int a, const long long int b)
{
	return (a > b);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;		
		scanf("%d %d",&n,&m);
		int i,j;
		for(i=0;i<n;i++)
			scanf("%lld",&l[i]);

		for(j=0;j<m;j++)
		{		
			scanf("%d %d %d",&a[j],&b[j],&c[j]);
			d[j]=(long long int)a[j]*a[j]+(long long int)b[j]*b[j]+(long long int)c[j]*c[j];
		}
		sort(l,l+n, myfun);
		sort(d,d+m, myfun);
		//for(i=0; i<n; i++)
		//	printf("%d", l[i]);
		//printf("\n\n");
		int cnt=0;
		for(i=0;i<n;i++)	
		{
			if(l[i]*l[i] <= d[0])
				break;
			cnt++;
		}
	
		printf("%d\n",n-cnt);
		
	}
	return 0;
}
