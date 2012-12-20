#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long i64;
main()
{
      i64 maxdiag,diag,len[50000];
      i64 l,h,b,i;
      i64 t,n,m;
      cin>>t;
      while(t--)
      {
                maxdiag=0;
                cin>>n>>m;
                for(i=0;i<n;i++)scanf("%lld",&len[i]);
                for(i=0;i<m;i++){
                                 scanf("%lld%lld%lld",&l,&h,&b);
                                 diag=l*l+b*b+h*h;
                                 if(diag>maxdiag)maxdiag=diag;
                                 }
                int ct=0;
                for(i=0;i<n;i++)if(maxdiag>=len[i]*len[i])ct++;
                printf("%d\n",ct);
                
      }
      return 0;
      
}
