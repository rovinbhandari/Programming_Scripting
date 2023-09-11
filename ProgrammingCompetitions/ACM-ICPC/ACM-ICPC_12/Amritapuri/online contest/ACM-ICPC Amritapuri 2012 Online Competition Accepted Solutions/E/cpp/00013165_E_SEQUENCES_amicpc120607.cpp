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
#include <limits>

using namespace std;
typedef long long LL;

const int max_n=100010;
const int minv=numeric_limits<int>::min();

int T,n,q;
char s[max_n+10];
int n0[max_n+1],n1[max_n+1];

int p2;
struct STel
{
	int lr,rr,val; //[ll,rr)
	STel(){}
	STel(int lr_, int rr_, int val_) {lr=lr_; rr=rr_; val=val_;}
};
STel ST[4*max_n+10];

void initST(int ix, int l, int r) //[l,r)
{
	ST[ix].lr=l; ST[ix].rr=r;
	if(l+1!=r)
	{
		initST(2*ix+1,l,(l+r)/2);
		initST(2*ix+2,(l+r)/2,r);
		ST[ix].val=max(ST[2*ix+1].val,ST[2*ix+2].val);
	}
	else
	{
		if(l<=n)
			ST[ix].val=n0[l]-n1[l];
		else
			ST[ix].val=minv;
	}
	
	//cerr<<ix<<" "<<l<<" "<<r<<" "<<ST[ix].val<<endl;
}

int queryST(int ix, int l, int r)
{
	//cerr<<ix<<" "<<l<<" "<<r<<endl;
	int lc=2*ix+1, rc=2*ix+2;
	if(ST[ix].lr==l and ST[ix].rr==r+1)
		return ST[ix].val;
	else if(r<ST[lc].rr)
		return queryST(lc,l,r);
	else if(l>=ST[rc].lr)
		return queryST(rc,l,r);
	else
		return max( queryST(lc,l,ST[lc].rr-1) , queryST(rc,ST[rc].lr,r) );
}

void findp2()
{
	p2=1;
	while(p2<n+1)
		p2*=2;
}

int main()
{
	scanf("%d",&T);
	
	for(int z=0; z<T; ++z)
	{
		scanf("%d",&n);
		scanf("%s",s);
		
		n0[0]=0; n1[0]=0;
		for(int i=1; i<=n; ++i)
		{
			n0[i]=n0[i-1]+((s[i-1]=='0')?1:0);
			n1[i]=n1[i-1]+((s[i-1]=='1')?1:0);
		}
		
		//cerr<<"1"<<endl;
		
		findp2();
		initST(0,0,p2);
		
		scanf("%d",&q);
		for(int y=0; y<q; ++y)
		{
			//cerr<<"y:"<<y<<endl;
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",n1[b]-n0[a-1]+queryST(0,a-1,b));
		}
	}	
	
	return 0;
}