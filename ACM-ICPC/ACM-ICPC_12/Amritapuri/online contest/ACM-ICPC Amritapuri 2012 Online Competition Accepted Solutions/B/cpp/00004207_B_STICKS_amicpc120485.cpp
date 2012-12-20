using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

# define MAX 50100

long long l[MAX];
int main()
{
    int cases,n,m,i,ans;
    long long val,temp,a,b,c,maxlen;
    scanf("%d",&cases);
    while(cases--)
    {
         scanf("%d%d",&n,&m);
         maxlen=0;
         
         for(i=0;i<n;i++) scanf("%lld",&l[i]);
         
         for(i=0;i<m;i++)
         {
              scanf("%lld%lld%lld",&a,&b,&c);
              val=a*a+b*b+c*c;
              if(val>maxlen) maxlen=val;
         }
         
         ans=0;
         for(i=0;i<n;i++)
         {
              temp=l[i]*l[i];
              if(temp<=maxlen) ans++;
         }
         printf("%d\n",ans);
    }
    return 0;
}
