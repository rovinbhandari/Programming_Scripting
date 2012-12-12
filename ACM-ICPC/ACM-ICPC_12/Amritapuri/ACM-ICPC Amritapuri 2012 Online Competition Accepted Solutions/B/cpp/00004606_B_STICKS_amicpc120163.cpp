#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cassert>
#include<limits.h>

typedef unsigned long long ULL;
typedef long long LL;

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define ABS(a) ((a>0)?a:-a))

#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);
#define mp(a,b) make_pair(a,b)
#define PII pair<int,int>
#define MOD 1000000007
using namespace std;
int main()
{
    long long t,l[50000],j,boxl[50000],boxh[50000],boxw[50000],count,k,n,i,max,len;
    scanf("%lld",&t);
    while(t--)
    {
        count=0;
        scanf("%lld%lld",&n,&k);
        for(i=0;i<n;++i){
            scanf("%lld",&l[i]);
        }
        sort(l,l+n);
        max=INT_MIN;
        for(i=0;i<k;++i){
            scanf("%lld%lld%lld",&boxl[i],&boxw[i],&boxh[i]);

            len=(long long)(sqrt(boxl[i]*boxl[i]+boxw[i]*boxw[i]+boxh[i]*boxh[i]));
            if(len>max)
            max=len;
        }
        for(j=0;j<n;++j){
            if(max>=l[j])
            count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
