#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<map>
#include<stack>

#define sf scanf
#define pf printf
#define forn(i,a,n) for(i=a;i<n;i++)
#define M 1000000007

long long int w;
using namespace std;
int d4[50001],a[50001];
long long int l[50001],b[50001],h[50001];
int main()
{
    int t,ns,nb,i,j,count,mx;
    sf("%d",&t);
    //p=t;
    while(t--)
    {         //if(t!=p-1)
            //scanf("%c",&c);
              count=0;
              sf("%d %d",&ns,&nb);
              forn(i,0,ns)
              sf("%d",&a[i]);
              forn(i,0,nb)
              sf("%lld %lld %lld",&l[i],&b[i],&h[i]);
              forn(i,0,nb)
              {
                         //d1[i]=sqrt((l[i] * l[i]) + (b[i] * b[i]));
                         //d2[i]=sqrt((b[i] * b[i]) + (h[i] * h[i]));
                         //d3[i]=sqrt((l[i] * l[i]) + (h[i] * h[i]));
                         w=((l[i] * l[i]) + (b[i] * b[i]) + (h[i] * h[i]));
                         //cout <<"w = "<<w<<endl;
                         d4[i]=(int)sqrt (w);
                         //cout<<d4[i]<<endl;
                         
              }
              mx=*max_element(d4,d4+nb);
              forn(i,0,ns)
              {
                          
                                      if(a[i]<=mx)
                                      count++;
                          
              }
              pf("%d\n",count);
              
    }
    //system("pause");
    return 0;
}
