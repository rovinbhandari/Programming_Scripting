#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define LL long long int
#define ULL unsigned long long int
#define S(n)                                    scanf("%d",&n)
#define Sl(n)                                   scanf("%lld",&n)
#define Sf(n)                                   scanf("%lf",&n)
#define Ss(n)                                   scanf("%s",n)
#define mod 1000000007
using namespace std;
vector<int> a[30009];
int chsn[30009];
int main()
{
        int t,i,j,k,n,m;
        /*#ifndef ONLINE_JUDGE
        freopen("example.txt","r",stdin);
        #endif*/
        S(t);
        while(t--)
        {
                S(n);
                for(i=0;i<=n;i++)
                        a[i].clear();
                for(i=0;i<n;i++)
                {
                        int x;
                        S(x);
                        for(j=0;j<x;j++)
                        {
                                S(k);
                                a[i].push_back(k);
                                a[k].push_back(i);
                        }
                }
                int ans=1;
                CLR(chsn);
                for(i=0;i<n;i++)
                {       
                        if(chsn[i]!=0)
                                continue;
                        ans=(ans+ans)%mod;
                        queue<int> q;
                        q.push(i);
                        chsn[i]=1;
                        while(!q.empty())
                        {
                                k=q.front();
                                q.pop();
                                int x=chsn[k];
                                int cp=3-x;
                                for(j=0;j<a[k].size();j++)
                                {
                                        int r=a[k][j];
                                        if(chsn[r]==0)
                                        {
                                                chsn[r]=cp;
                                                q.push(r);
                                        }
                                        if(chsn[r]==cp)
                                                continue;
                                        if(chsn[r]==x)
                                        {
                                                printf("0\n");
                                                goto rr;
                                        }
                                }
                        }
                }
                printf("%d\n",ans);
                rr:;
        }
        return 0;
}