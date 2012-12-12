#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <math.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define SZ(a) a.size()
#define SORT(a) sort(a.begin(),a.end())

using namespace std;
 int n,m,a[500010];
 long long box[500010];

int main()
{
   //freopen("read.txt","r",stdin);
   //freopen("write.txt","w",stdout);

   int test;
   scanf("%d",&test);

   long long  x,y,z;
   while(test--)
   {
        scanf("%d %d",&n,&m);
        REP(i,n)
                scanf("%d",&a[i]);
        REP(i,m)
        {
                scanf("%lld %lld %lld",&x,&y,&z);
                box[i] = (int)sqrt((double)(x*x + y*y + z*z));
        }
        int max=0;
        REP(i,m)
         max = MAX(max,box[i]);
         int ans=0;
        REP(i,n)
           if(a[i]<= max)
                ans++;
        printf("%d\n",ans);
   }

  return 0;
}
