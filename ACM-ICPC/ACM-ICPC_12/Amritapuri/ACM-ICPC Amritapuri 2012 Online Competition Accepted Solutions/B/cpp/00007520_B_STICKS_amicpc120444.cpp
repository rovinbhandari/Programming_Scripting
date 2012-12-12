#include<stdio.h>
#include<algorithm>
#include<cmath>

using namespace std;
main()
{
      int i,j,k,t,n,m,ans;
      double a[50001],l,b,h,p;
      scanf("%d",&t);
      while(t--)
      {
                scanf("%d%d",&n,&m);
                for(i=0;i<n;i++)
                   scanf("%lf",&a[i]);
                sort(a,a+n);
                ans=0;k=0;
                for(i=0;i<m;i++)
                {
                                scanf("%lf%lf%lf",&l,&b,&h);
                                p=sqrt(l*l+b*b+h*h);
                                for(j=k;j<n;j++)
                               { if(a[j]>p)
                                {
                                k=j;break;}
                                else if(ans<n)
                                ans++;
                               }
                                }
             printf("%d\n",ans);
             }
             return 0;
             }
                                
                                
