#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<bitset>
#include<deque>
#include<utility>
#include<cstdlib>
#include<iomanip>
#include<cctype>
#include<climits>
#include<iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define equa(x,y)(x==y?1:0)
#define all(x) x.begin(),x.end()
#define vi  vector<int>
#define vvi vector<vector<int> >
#define vil vector<long long>
#define vvil vector<vector<long long> >
#define inpint(x) scanf("%d",&x)
#define inpll(x) scanf("%lld",&x)
#define inpull(x) scanf("%ull",&x)
#define inpstr(x) scanf("%s",x)
#define gcd __gcd
#define INF 2147483647
string tostr(long long x) { stringstream ss; ss << x; return ss.str(); }
long long toint(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }
#define fo(x,y,z) for(int x=y;x<=z;x++)
#define re(x,y,z) for(int x=y;x>=z;x--)
#define LIMIT 1000
vector<int> pri;
void sieve(){vector < bool > prime ( LIMIT + 1 , true ) ;prime [ 0 ] = prime [ 1 ] = false ;for ( int i = 2 ; i <= LIMIT ; ++ i )if ( prime [ i ] )if ( i * 1ll * i <= LIMIT )for ( int j = i * i ; j <= LIMIT ; j += i )prime [ j ] = false ;for(int i=2;i<=LIMIT;i++)if(prime[i])pri.push_back(i);}
int arr[100001];
struct segm
{
	int zeze,onon,zeron,max;
};
segm tre[400001];
void build(int node,int a,int b)
{

	if(a==b)
	{
		tre[node].max=1;
		tre[node].onon=arr[a]==1;
		tre[node].zeze=arr[a]==0;
		tre[node].zeron=0;
		return;
	}
	int mid=(a+b)/2;
	build(2*node,a,mid);
	build(2*node+1,mid+1,b);
	tre[node].zeze=tre[2*node].zeze+tre[2*node+1].zeze;
	tre[node].zeron=max(max(tre[2*node].zeze+tre[2*node+1].zeron,tre[2*node].zeze+tre[2*node+1].onon),tre[2*node].zeron+tre[2*node+1].onon);
	tre[node].onon=tre[2*node].onon+tre[2*node+1].onon;
	return;
}
segm query(int node,int a,int b,int i,int j)
{
	if(i==a&&j==b)
		return tre[node];
	int mid=(a+b)/2;
	if(j<=mid)
		return query(2*node,a,mid,i,j);
	else if(i>mid)
		return query(2*node+1,mid+1,b,i,j);
	else
	{
		segm p1,p2,p3;
		p1 = query(2*node, a, mid, i, mid);
		p2 = query(2*node+1, mid+1, b, mid+1, j);

		p3.zeze = p1.zeze + p2.zeze;
		p3.zeron =max(max(p1.zeze+p2.zeron,p1.zeze+p2.onon),p1.zeron+p2.onon);

		 p3.onon=p1.onon+p2.onon;
	//return;
        return p3;
	}

}
char str[100001];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t;
	inpint(t);
	while(t--)
	{
		int n;
		inpint(n);
		scanf("%s",str);
		int len=strlen(str)-1;
		fo(i,0,len)if(str[i]=='1')arr[i]=1;else arr[i]=0;
		//fo(i,0,n-1)
		build(1,0,n-1);
		int q;
		inpint(q);
		while(q--)
		{
			int l,r;
			inpint(l);inpint(r);
			l--;r--;
			segm t=query(1,0,n-1,l,r);
			int ans=max(t.onon, max(t.zeron,t.zeze));
			printf("%d\n",ans);
		}
	}
  return 0;
}
