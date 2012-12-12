# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,a,b) for(int i=a;i<b;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS (double)(1e-9)
#define PI (double)(3.141592653589793)
#define MOD 1000000007

int a[20005],b[20005],cnt,num,val;
pair<int,int> top;
set<int> v[20005];
bool seen[20005];

LL mod_exp(int cnt)
{
	if(cnt==1)
		return 2;
	if(cnt%2==0)
	{
		LL temp=mod_exp(cnt/2);
		return (temp*temp)%MOD;
	}
	else
	{
		LL temp=mod_exp(cnt-1);
		return (2*temp)%MOD;
	}
}

int main()
{
	int t, n;
	t=GI;
	while(t--)
	{
		memset(a,-1,sizeof a);
		memset(b,-1,sizeof b);
		memset(seen,false,sizeof seen);
		cnt=0;
		n=GI;
		REP(i,0,n)
			v[i].clear();
		REP(i,0,n)
		{
			num=GI;
			REP(j,0,num)
			{
				val=GI;
				if(v[i].find(val)==v[i].end())
					v[i].insert(val);
				if(v[val].find(i)==v[val].end())
					v[val].insert(i);
			}
		}
		
		REP(i,0,n)
		{
			if(seen[i])	continue;
			seen[i]=true;
			cnt++;
			a[i]=cnt;
			stack<pair<int,int> >s;
			TR(it,v[i])
			{
				s.push(mp(*it,1));
			}
			while(!s.empty())
			{
				top=s.top();s.pop();
				if(seen[top.first])	continue;
				seen[top.first]=true;
				TR(it,v[top.first])
				{
					if(seen[*it]) continue;
					
					if(top.second==0)
					{
						if(a[*it]!=-1)
						{
							printf("0\n");
							goto next;
						}
						s.push(mp(*it,1));
						b[*it]=cnt;
					}
					if(top.second==1)
					{
						if(b[*it]!=-1)
						{
							printf("0\n");
							goto next;
						}
						s.push(mp(*it,0));
						a[*it]=cnt;
					}
				}
			}
		}
		printf("%lld\n",mod_exp(cnt)); // second time
		next:;		
	}
	return 0;
}


