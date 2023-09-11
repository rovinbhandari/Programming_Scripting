#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
main()
{
      int t,n,l,h,i,a[1000],temp,j,k,sum1,sum2,sum3;
      scanf("%d",&t);
      while(t--)
      {
                scanf("%d%d%d",&n,&l,&h);
                for(i=0;i<n;i++)scanf("%d",&a[i]);
                sort(a,a+n);
                //for(i=0;i<n;i++)printf("%d ",a[i]);
                //printf("\n");
                int highindex=n;
                
                /*if(l/3>a[n-1]||h/3<a[0]||h<l){
                             printf("0\n");
                             continue;
                             }*/
                long long ct=0;
                for(i=0;i<n-2&&a[i]<=h/3;i++)
                {
                        //int flag1=0;                  
                        sum1=a[i];                           
                        for(j=i+1;j<n-1;j++)
                        {
                                            
                                  //int flag=0;              
                                  sum2=sum1+a[j];
                                  //if(sum2>h){  flag1=1;break; }         
                                  int lowi=j+1;
                                  //if(lowi<l/3)lowi=l/3;       
                                   for(k=lowi;k<n;k++)   
                                   {
                                            sum3=sum2+a[k];
                                            
                                            if(sum3>h){//flag=1;
                                            break;}
                                            if(sum3<l)continue;
                                            if(sum3<=h&&sum3>=l){ct++;}
                                                        
                                   }    
                                   //if(flag){flag1=1;break;}
                        }   
                        //if(flag1)break;     
                }
                printf("%lld\n",ct);
                /*
                printf("Sorted array\n");
                for(i=0;i<n;i++)printf("%d ",a[i]);
                printf("\n");
                printf("indexl=%d indexh=%d\n",indexl,indexh);
                printf("l=%d h=%d\n",l,h);
                long long num=indexh-indexl;
                printf("%lld\n",num*(num-1)*(num-2));*/
                
      }
      return 0;
}
