#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <cassert>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define reprev(i,a,n) for(int i=a;i>n;i--)
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d ",n)
#define outln(n) printf("%d\n",n)
#define outl(n) printf("%lld ",n)
#define outlln(n) printf("%lld\n",n)
#define LL long long 
#define pb push_back
using namespace std;
#define mod 1000000007
LL power2(int n)
{
	if(n==1)
		return 2;
	if(n==0)
		return 1;
	if(n%2)
	{
		LL l=power2(n/2);
		return (2*l*l)%mod;
	}
	else	
	{
		LL l=power2(n/2);
		return (l*l)%mod;
	}
}
map<int,set<int> > m;
int fun(int visited[],int index)
{
	visited[index]=1;
	queue<int> q;
	q.push(index);
	int k,k1;
	set<int>::iterator it;

	while(!q.empty())
	{
		k=q.front();q.pop();
		k1=visited[k];
		for(it=m[k].begin();it!=m[k].end();it++)
		{
			if(visited[*it]==0)
			{
				q.push(*it);
				visited[*it]=3-k1;
			}
			else if(visited[*it]==k1)
				return -1;	
			
		}
	}
	return 1;
}
int main()
{
	int A;in(A);
	int n,m1,k;
	while(A--)
	{
		int visited[20002]={0};
		m.clear();
		in(n);
		rep(i,0,n)
		{
			in(m1);
			rep(j,0,m1)
			{
				in(k);
				m[i].insert(k);
				m[k].insert(i);
			}
		}
		int cnt=0,lp=0;
		rep(i,0,n)
		{
			if(visited[i]==0)
			{
				lp=fun(visited,i);
				cnt++;
			}
			if(lp==-1)
				break;
		}
		if(lp==-1)
			cout<<0<<endl;
		else
			cout<<power2(cnt)<<endl;

	}

	return 0;
}
