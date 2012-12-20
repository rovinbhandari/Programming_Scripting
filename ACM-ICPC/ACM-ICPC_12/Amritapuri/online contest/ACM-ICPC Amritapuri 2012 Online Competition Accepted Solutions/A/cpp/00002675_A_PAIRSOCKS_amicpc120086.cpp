#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[100];
		int r=0,g=0,b=0,w=0;
		scanf("%s",s);
		int i,j;
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]=='R')
			{
				r++;
			}
			if(s[i]=='G')
			{
				g++;
			}
			if(s[i]=='B')
			{
				b++;
			}
			if(s[i]=='W')
			{
				w++;
			}
		}
		if(r%2==0&&b%2==0&&g%2==0&&w%2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
