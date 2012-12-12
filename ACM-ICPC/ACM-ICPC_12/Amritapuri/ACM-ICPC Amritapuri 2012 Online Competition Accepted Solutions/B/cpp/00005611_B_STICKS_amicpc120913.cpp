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



int n ,m;
int t;


int main()
{

    s(t)

    for(int i=0;i<t;i++)
    {

        s(n)
        s(m)

        int stk[n];
        int a[m];
        int b[m];
        int c[m];

        double max =0.0;
        double temp =0.0;

        for(int j=0;j<n;j++)
        s(stk[j])


        for(int j=0;j<m;j++)
        {
            s(a[j])
            s(b[j])
            s(c[j])

        }

        for(int j=0;j<m;j++)
        {
            temp = sqrt(a[j]*a[j]*1.0 + b[j]*b[j]*1.0 + c[j]*c[j]*1.0  );

            if(temp>max)
            max = temp;
        }

        //printf("%f\n",max);

        int q=0;

        for(int j=0;j<n;j++)
        {
            if(stk[j]*1.0 <=max)
            q++;
        }

        p(q)

    }

}
