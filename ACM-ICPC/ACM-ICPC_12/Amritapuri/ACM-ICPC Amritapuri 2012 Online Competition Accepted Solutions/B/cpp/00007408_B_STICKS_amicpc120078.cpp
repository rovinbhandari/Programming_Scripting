
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
   _ Problem :
   _._._._._._._._._._._._._._._._._._._._._.*/

#include<algorithm>
#include<assert.h>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

vector<int>V;

typedef struct Box
{
	int a;
	int b;
	int c;
}Box;

vector< Box* > B;

vector< int > f,s;
int n,m;

int dp[50002][3];
long long int sq[50002];

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		cin>>n>>m;
		long long int a,b,c;
		long long int ss=0,mx=-1;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			V.push_back(x);
		}
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			if(mx < (a*a+b*b+c*c))
				mx=a*a+b*b+c*c;
		}
		int co=0;
		for(int i=0;i<n;i++)
		{
			if(V[i]<=sqrt(mx))
				co++;
		}
		cout<<co<<endl;
		V.clear();
	}
	return 0;
}
