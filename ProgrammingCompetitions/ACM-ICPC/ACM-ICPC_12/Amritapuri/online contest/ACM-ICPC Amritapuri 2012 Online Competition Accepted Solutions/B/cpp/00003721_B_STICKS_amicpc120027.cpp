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
using namespace std;
double a[100009];
int main()
{
        int t,i,j,k,n,m;
        /*#ifndef ONLINE_JUDGE
        freopen("example.txt","r",stdin);
        #endif*/
        S(t);
        while(t--)
        {
                S(n);S(m);
                for(i=0;i<n;i++)
                        Sf(a[i]);
                int x1,y1,z1;
                double maxi=0;
                double x,y,z;
                for(i=0;i<m;i++)
                {
                        Sf(x);Sf(y);Sf(z);
                        double c=x*x+y*y+z*z;
                        c=sqrt(c);
                        maxi=max(maxi,c);
                }
                int cunt=0;
                for(i=0;i<n;i++)
                {
                        if(a[i]<=maxi)
                                cunt++;
                }
                printf("%d\n",cunt);
                
        }
        return 0;
}