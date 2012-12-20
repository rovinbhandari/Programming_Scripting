#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>





#include <set>
#include <map>
#include <deque>
#include <string>
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define LL long long int
#define ULL unsigned long long int
#define S(n)					scanf("%d",&n)
#define Sl(n)					scanf("%lld",&n)
#define Sf(n) 					scanf("%lf",&n)
#define Ss(n) 					scanf("%s",n)
using namespace std;
struct Node
{
	int ans;
	int zeros;
	int ones;
		
	
};

Node Mrg(Node a,Node b)
{
	Node c;
	c.zeros=a.zeros+b.zeros;
	c.ones=a.ones+b.ones;
	
	c.ans=max((a.ans+b.ones),max(a.zeros+b.ans,max(a.zeros+b.zeros,a.ones+b.ones)));
	return c;
}
Node T[400010];

char arr[200000];
void Build(int n,int s,int e)
{
	if(s==e)
	{
		T[n].ans=1;
		T[n].zeros=arr[s]=='0';
		T[n].ones=arr[s]=='1';
		return;
	}
	
	int m=(s+e)>>1;
	int n1=n<<1;
	Build(n1,s,m);
	Build(n1+1,m+1,e);
	T[n]=Mrg(T[n1],T[n1+1]);
}

Node Query(int n,int b,int e,int i,int j)
{
	
	
	if(b>=i&&e<=j)
	{
		return T[n];
	}
	
	int m=(b+e)>>1;
	int n1=n<<1;
	
	if(j<=m)
	return Query(n1,b,m,i,j);
	if(i>m)
	return Query(n1+1,m+1,e,i,j);
	
	Node lft=Query(n1,b,m,i,j);
	Node rt=Query(n1+1,m+1,e,i,j);
	
	return Mrg(lft,rt);
}


int main()
{
	int tests;
	scanf("%d",&tests);
	while(tests--)
	{
		
		int i,j,k;
		int num;
		S(num);
		Ss(arr);
		Build(1,0,num-1);
		int q;
		S(q);
		for(i=0;i<q;i++)
		{
			S(j),S(k);
			j--,k--;
			Node a=Query(1,0,num-1,j,k);
			printf("%d\n",a.ans);
		}
	}
    return 0;
}
