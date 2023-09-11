#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
       int l[n];
       unsigned long long int a,b,c;
       unsigned long long int  res=0;
       unsigned long long int d,max=0;
       for(int i=0;i<n;++i)
       scanf("%d",&l[i]);
       for(int i=0;i<m;++i)
       {
           scanf("%llu%llu%llu",&a,&b,&c);
           d=(a*a)+(b*b)+(c*c);//cout<<d<<endl;
           d=sqrt(d);
          // cout<<d<<endl;
           if(d>max)
           max=d;
       }
       for(int i=0;i<n;++i)
       {
           if(l[i]<=max)
           ++res;
       }
       printf("%llu\n",res);
    }
}
