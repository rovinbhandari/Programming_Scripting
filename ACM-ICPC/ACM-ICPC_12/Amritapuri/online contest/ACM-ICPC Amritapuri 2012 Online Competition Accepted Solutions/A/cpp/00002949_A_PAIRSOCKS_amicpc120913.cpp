#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<queue>
#include<sstream>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo (int)13e7
#define s(n)	 scanf("%d",&n);
#define sl(n) scanf("%lld",&n);
#define sf(n) scanf("%lf",&n);
#define p(n) printf("%d\n",n);
#define fill(a,v) memset(a, v, sizeof a)
#define ull unsigned long long
#define ll long long
#define bitcount __builtin_popcount
#define all(x) x.begin(), x.end()
#define pb( z ) push_back( z )
#define gcd	 __gcd

using namespace std;

int b=0,r=0,w=0,g=0;

string x;

int main()
{

    int n;

    s(n)

    for(int i=0;i<n;i++)
    {
        cin>>x;
        r=0;
        b=0;
        w=0;
        g=0;

        for(int j=0;j<x.length();j++)
        {
            if(x[j]=='R')
            r = (r+1 )%2;

            else if(x[j]=='W')
            w = (w+1 )%2;

            else if(x[j]=='G')
            g = (g+1 )%2;

            else if(x[j]=='B')
            b = (b+1 )%2;

            else{}

        }

        if( r==0 && b==0 && w==0 && g==0)
        printf("YES\n");
        else
        printf("NO\n");

    }



}
