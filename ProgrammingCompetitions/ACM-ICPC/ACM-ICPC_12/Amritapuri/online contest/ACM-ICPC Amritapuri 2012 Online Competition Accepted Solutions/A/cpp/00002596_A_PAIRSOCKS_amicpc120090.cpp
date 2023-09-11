// LIBRARIES
#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<algorithm>

// DATA STRUCTURES
#include<string>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<map>

// OTHERS
#define L(a) list< a >
#define V(a) vector< a >
#define S(a) stack< a >
#define Q(a) queue< a >
#define P(a,b) pair< a , b >
#define M(a,b) map< a , b >
#define H(a) priority_queue< a >
#define Hm(a) priority_queue< a, vector<a>, greater<a> >
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FOR_D(i,a,b) for(int i=a-1;i>=b;i--)
#define f first
#define s second
#define pb push_back
typedef long long int lli;
using namespace std;

int t;
string c;
int r,g,b,w;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin >> c;
		r=g=b=w=0;
		FOR(i,0,c.size())
		{
			if(c[i]=='R')
				r++;
			if(c[i]=='G')
				g++;
			if(c[i]=='B')
				b++;
			if(c[i]=='W')
				w++;
		}
		if(r%2==0 && w%2==0 && b%2==0 && g%2==0)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}
