#include<iostream>
#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<set>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
          int tcases,n,l,h,val,low,high,count,i,a[100010],j,firstindex,lastindex;
          
          scanf("%d",&tcases);
          
          while(tcases--)
          {
                         scanf("%d %d %d",&n,&l,&h);
                         
                         for(i=0;i<n;i++)
                         {
                                         scanf("%d",&a[i]);
                                         //b[i]=a[i];
                         }
                         
                         sort(a,a+n);
                         count=0;
                         
                         for(i=0;i<n;i++)
                         {
                                         for(j=i+1;j<n;j++)
                                         {
                                                         val=a[i]+a[j];
                                                         
                                                         low=l-(a[i]+a[j]);
                                                         
                                                         high=h-(a[i]+a[j]);
                                                         
                                                         if(high<0)
                                                         continue;
                                                         
                                                         else if(low<0)
                                                         {
                                                                    int *p=lower_bound(a+j+1,a+n,1);   
                                                                    int *q=upper_bound(a+j+1,a+n,high);
                                                                    
                                                                    //firstindex=p-a;
                                                                    //lastindex=q-a;
                                                                    //printf("p is %d\n",p);
                                                                    //printf("q is %d\n",q);
                                                                    count=count+(q-p);
                                                         }
                                                         
                                                         else
                                                         {
                                                                    int *p=lower_bound(a+j+1,a+n,low);
                                                                    int *q=upper_bound(a+j+1,a+n,high);
                                                                     
                                                                     //firstindex=p-a;
                                                                     //lastindex=q-a;
                                                                     //printf("p is %d\n",p);
                                                                     //printf("q is %d\n",q);
                                                                    
                                                                     count=count+(q-p);
                                                         }
                                         }
                         }
                         
                         printf("%d\n",count);
                         
          }
          
//getch();
return 0;

}
