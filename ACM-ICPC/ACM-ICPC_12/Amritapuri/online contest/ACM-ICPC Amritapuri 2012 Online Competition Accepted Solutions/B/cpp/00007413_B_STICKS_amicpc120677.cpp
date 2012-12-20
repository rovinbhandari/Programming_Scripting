#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <iomanip>
#include <limits.h>

using namespace std;

#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(X) (X)*(X)

typedef long long LL;

int N,i,j,T,M,L[50000+10],maxlen;
struct cube
{
    int a,b,c;
} dm[50000+10];
long long maxdiag;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&M);
        for(i=0;i<N;i++)
            scanf("%d",L+i);
        maxlen=0;
        maxdiag=0;
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&dm[i].a,&dm[i].b,&dm[i].c);
            maxlen=max(maxlen,dm[i].a);
            maxlen=max(maxlen,dm[i].b);
            maxlen=max(maxlen,dm[i].c);
            long long sq=sqr((LL)dm[i].a)+sqr((LL)dm[i].b)+sqr((LL)dm[i].c);
            maxdiag=max(maxdiag,sq);
        }
        //cout<<maxdiag<<endl;
        int ans=0;
        for(i=0;i<N;i++)
        {
            long long lsq=sqr((LL)L[i]);
            if(lsq<=maxdiag)
              ans++;
        }
        printf("%d\n",ans);
        //scanf("%*c");
    }


    return 0;
}
