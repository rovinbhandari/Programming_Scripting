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

const int max_n=1010;
const int lim=1000010;

int T,n,l,h;
int a[max_n];
int p[lim+1],q[lim+1];

int main()
{
	scanf("%d",&T);
	
	for(int z=0; z<T; ++z)
	{
		scanf("%d%d%d",&n,&l,&h);
		
		for(int i=0; i<n; ++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		
		int j=0;
		for(int i=1; i<=lim; ++i)
		{
			while(j<n and a[j]<i)
				++j;
			p[i]=j;
			//if(i<=15) cout<<i<<" p[i]:"<<p[i]<<endl;
		}
		
		j=n-1;
		for(int i=lim; i>=1; --i)
		{
			while(j>=0 and a[j]>i)
				--j;
			q[i]=j;
			//if(i<=15) cout<<i<<" q[i]:"<<q[i]<<endl;
		}
		
		int res=0;
		int lr,rr;
		for(int i=0; i<n; ++i)
		{
			for(int k=i+1; k<n; ++k)
			{
					lr = ( ((l-a[i]-a[k])<0) ? (k+1) : p[l-a[i]-a[k]] );
					if(lr<(k+1)) { lr=k+1; }
					
					rr = ( ((h-a[i]-a[k])<0) ? (-1) : q[h-a[i]-a[k]] );
					
					//cout<<i<<" "<<k<<" : "<<l-a[i]-a[k]<<" "<<h-a[i]-a[k]<<" : "<<lr<<" "<<rr<<endl;
					
					if(lr<=rr)
						res+=(rr-lr+1);
			}
		}
		
		printf("%d\n",res);
	}
	
	return 0;
}