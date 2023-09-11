
#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int main()
{
    int l,h,t,n,i,j,k,sum,count,max,min;
    scanf("%d",&t);
     int *ma,*mi;
    while(t--)
    {
              scanf("%d%d%d",&n,&l,&h);
              int a[n];
              for(i=0;i<n;i++)
              {
                              scanf("%d",&a[i]);
              }
             count=0;
             sort(a,a+n);
             for(i=0;i<n-1;i++)
             {
                               sum=0;
                               for(j=i+1;j<n;j++)
                               {
                                               sum=a[i]+a[j];
                                               min=l-sum;
                                               max=h-sum;
                                               if(max<=0)
                                               continue;
                                               if(min<0)
                                               {
                                               mi=lower_bound(a+j+1,a+n,1);
                                               }
                                               else
                                               {
                                               mi=lower_bound(a+j+1,a+n,min);
                                               }
                                               ma=upper_bound(a+j+1,a+n,max);   
                                               count+=(ma-mi);
                               }
             } 
              printf("%d\n",count);   
              }    
}                             
