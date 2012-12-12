#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#define LL long long
using namespace std; 
LL maxi(LL a,LL b)
{
           if(a>b)
            return a;
            else
            return b;
}

LL a[50005];
int main()
{int t;
    scanf("%d",&t);
    
    for(;t;t--)
    {
               LL n,m;
               scanf("%lld %lld",&n,&m);
               
               for(int i=0;i<n;i++)
               {
                       scanf("%lld",&a[i]);
                       }
                       
                       double res=-1.0;
                       LL x,y,z;
                       for(int i=0;i<m;i++)
                       {
                               scanf("%lld %lld %lld",&x,&y,&z);
                               res=maxi(res,sqrtl((x*x+y*y)+z*z));
                       }
                       
                       LL p=0;
                       for(int i=0;i<n;i++)
                       {
                               if(a[i]<=res)
                               p++;
                       }
                       
                       printf("%lld\n",p);
               }
    //getch();
return 0;
}
               
    

