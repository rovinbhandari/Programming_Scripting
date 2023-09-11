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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[100];
		scanf("%s",s);
		int r=0,g=0,w=0,b=0;
		rep(i,0,strlen(s))
		{
			if(s[i]=='B')
				b++;
			if(s[i]=='W')
				w++;
			if(s[i]=='R')
				r++;
			if(s[i]=='G')
				g++;
		}
		if(g%2==0 && b%2==0 && r%2==0 && w%2==0)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}
