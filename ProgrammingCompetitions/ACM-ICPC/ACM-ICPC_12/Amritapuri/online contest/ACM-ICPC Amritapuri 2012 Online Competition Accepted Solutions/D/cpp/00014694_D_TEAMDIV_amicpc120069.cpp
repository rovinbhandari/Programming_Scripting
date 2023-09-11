// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>
#include<sstream>

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
int main()
{
	int i,j,n,t,a,b,m,r,g,gp,flag,grp;

	long long int ct;
	int arr[20010];
	VI rival[20010];
	bool done[20010];

	si(t);
	while(t--)
	{
		queue<int> up;
		flag = 0;
		rep(i,20010)
		{
			arr[i]=-1;
			done[i] = false;
		}
		rep(i,20010)
			rival[i].clear();
		ct = 1;
		si(n);
		rep(i,n)
		{
			si(r);
			rep(j,r)
			{
				si(a);
				rival[i].pb(a);
				rival[a].pb(i);
			}
		}

		/*		rep(i,n)
				{
				printf("i: %d :  ",i);
				rep(j,rival[i].size())
				printf("%d ",rival[i][j]);
				printf("\n");
				}
		 */
		rep(i,n)
		{
			if(done[i])
				continue;
			up.push(i);
			while(!up.empty())
			{
				int el = up.front();
				up.pop();
				if(done[el])
					continue;
				done[el] = true;

				flag = 0;
				int i1 = el;
				rep(j,rival[i1].size())
					up.push(rival[i1][j]);
				if(arr[i1] == -1)
				{
					//unass
					g = -1;
					rep(j,rival[i1].size())
					{
						if(arr[rival[i1][j]] != -1)
						{
							if (arr[rival[i1][j]] != g)
							{
								if(g == -1)
								{
									g = arr[rival[i1][j]];
								}
								else
								{
									flag = 1 ;
									break;
								}
							}
						}
					}

					if( g == -1 )
					{
						ct *= 2 ;
						ct = ct % 1000000007;
						arr[i] = 0;
						rep(j,rival[i1].size())
							arr[rival[i1][j]] = 1;
					}
					else
					{
						rep(j,rival[i1].size())
							arr[rival[i1][j]] = g;
						if(g == 1)
							arr[i1] = 0;
						else
							arr[i1] = 1;
					}

					if(flag == 1)
					{
						printf("0\n");
						break;
					}
				}
				else
				{
					//ass
					gp = arr[i1];
					rep(j,rival[i1].size())
					{
						if(arr[rival[i1][j]] == -1 )
						{
							if(gp == 1)
								arr[rival[i1][j]]=0;
							else
								arr[rival[i1][j]]=1;
						}
						else
						{
							if(arr[rival[i1][j]] == gp)
							{
								flag = 1;
								break;
							}
						}
					}
					if(flag == 1 )
					{
						printf("0\n");
						break;
					}
				}
			}
			if(flag == 1)
				break;
		}
		if(flag == 0)
			printf("%lld\n",ct);

	}

	return 0;
}

