#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define MUL(a,b) ((a)%MOD*(b)%MOD)%MOD
#define SQR(a) ((a)*(a))
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define f(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int main()
{
    int t;si(t);
    while(t--)
    {
        int n,m;si(n);si(m);
        ll max=0,temp=0, cc=0;
        ll l[n],a[m],b[m],c[m];
        f(i,0,n)cin>>l[i];
        f(i,0,m)
        {
            cin>>a[i]>>b[i]>>c[i];
            temp=(a[i]*a[i]+b[i]*b[i]+c[i]*c[i]);
            if(max<temp)max=temp;
        }
        f(i,0,n)if(l[i]*l[i]<=max)cc++;
        cout<<cc<<endl;
    }
    return 0;
}
