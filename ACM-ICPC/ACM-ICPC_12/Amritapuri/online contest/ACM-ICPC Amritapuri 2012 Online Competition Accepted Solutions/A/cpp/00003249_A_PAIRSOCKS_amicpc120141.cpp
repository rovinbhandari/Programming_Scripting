/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

   * File Name : 1.cpp

   * Purpose :

   * Creation Date : 04-11-2012

   * Last Modified : Sunday 04 November 2012 09:50:41 AM IST

   * Created By :  Shoaib Khan

   _._._._._._._._._._._._._._._._._._._._._.*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b)  for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n)    FOR(i,0,n)
#define INF     INT_MAX
#define ALL(x)      x.begin(),x.end()
#define LET(x,a)    __typeof(a) x(a)
#define IFOR(i,a,b)     for(LET(i,a);i!=(b);++i)
#define EACH(it,v)  IFOR(it,v.begin(),v.end())
#define pb      push_back
#define sz(x)       int(x.size())
#define mp      make_pair
#define fill(x,v)   memset(x,v,sizeof(x))
#define si(n)       scanf("%d",&n)
#define pi(n)       printf("%d ",n)
#define pil(n)      printf("%d\n",n)
#define sl(n)       scanf("%lld",&n)
#define sd(n)       scanf("%lf",&n)
#define ss(n)       scanf("%s",n)

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef queue<int> QU;
int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		char str[100];
		cin >> str;
		int len = strlen(str);
		int r=0,g=0,b=0,w=0;
		for(int j=0;j<len;j++){
			if(str[j]=='R')
				r++;
			else if(str[j]=='B')
				b++;
			else if(str[j]=='G')
				g++;
			else if(str[j]=='W')
				w++;
		}
		if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
