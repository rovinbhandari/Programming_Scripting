#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;

#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()

typedef long long LL;
const int INF = 1000000000;
const LL INFLL = LL(INF) * LL(INF);
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }

int main()
{
    //freopen("ip.txt","r",stdin);
    //freopen("op.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,l,h;
        scanf("%d %d %d",&n,&l,&h);
        int a[1001];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int lo=j+1,hi=n-1,top=n,bottom=j;
                while(lo<=hi)
                {
                    int mid=(lo+hi)/2;
                    if(a[i]+a[j]+a[mid]<l)
                    {
                        bottom=mid;
                        lo=mid+1;
                    }
                    else
                    {
                        hi=mid-1;
                    }
                }
                lo=j+1;hi=n-1;
                while(lo<=hi)
                {
                    int mid=(lo+hi)/2;
                    if(a[i]+a[j]+a[mid]>h)
                    {
                        top=mid;
                        hi=mid-1;
                    }
                    else
                    {
                        lo=mid+1;
                    }
                }
                //cout<<i<<" "<<j<<" "<<bottom<<" "<<top<<"\n";
                ans+=top-bottom-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

