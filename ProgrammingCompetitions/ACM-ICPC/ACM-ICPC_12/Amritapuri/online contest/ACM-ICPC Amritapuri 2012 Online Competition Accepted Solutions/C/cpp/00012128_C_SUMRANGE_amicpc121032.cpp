#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

//pair<int,int> P;
//map<int,int> mymap;
//map<string,int> mymap;
//map<string,int>::iterator it;
//vector<int> vec;
//vector<pair<int,int> > vec2;
//vector<int>::iterator it;
//for(it=mymap.begin();it!=mymap.end();it++)

typedef unsigned long long int ull;
typedef long long int ll;
template <class T> T ABS(const T &x) {return x>0? x:-x;}
template <class T> void SWAP(T &x, T &y) {T z=x; x=y; y=z;}
//const ld PI = 3.14159265358979323846;
//const ld EPSILON = 0.000000000001;
#define all(c) (c).begin(),(c).end()
#define sz 100000
#define INF 2147483647
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define mod 1000000007
#define MAXN 1000010
/*
inline int FAST_IO()
{
    int xxxx;
    char ch;
    int Negativity=0;
    while (((ch=getchar_unlocked()) < 48 || ch > 57) && ch != '-');
    xxxx=0;
    if (ch == '-') Negativity=1;
    else xxxx = ch-48;
    while ((ch=getchar_unlocked()) >= 48 && ch <= 57) xxxx=xxxx*10+ch-48;
    if (Negativity) return -xxxx;
    else return xxxx;
}
*/

int main()
{
	int tc,n,l,h,lb,ub,tmp,ans;
	int arr[1111];
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d%d",&n,&l,&h);
		REP(i,n)
		{
			scanf("%d",&arr[i]);
		}
		
		vector<int> v(arr, arr+n);
		sort(v.begin(),v.end());
		//REP(i,n) cout<<v[i]<<" ";
		//cout<<endl<<endl;
		
		ans=0;
		FOR(i,0,n)
		{
			FOR(j,i+2,n)
			{
				tmp=l-(v[i]+v[j]);
				if(tmp>v[j]) continue;
				if (tmp<=v[i])
				lb=i+1;
				else
				lb=lower_bound (v.begin()+i+1, v.begin()+j, tmp ) - v.begin();
				
				tmp=h -(v[i]+v[j]);
				//cout<<h<<" "<<v[i]<<" "<< v[j]<<" "<<tmp<<endl;
				if(tmp<v[i]) continue;
				if (tmp>=v[j])
				ub=j;
				else
				ub =upper_bound (v.begin()+i+1, v.begin()+j, tmp ) - v.begin();
				
				if(ub>lb)
				{
				ans+=(ub-lb);
				//cout<<i<<" "<<lb<<" "<<ub<<" "<<j<<" ";
				//cout<<endl;
				}
			}
		}
		printf("%d\n",ans);		
	}
	return 0;
}
