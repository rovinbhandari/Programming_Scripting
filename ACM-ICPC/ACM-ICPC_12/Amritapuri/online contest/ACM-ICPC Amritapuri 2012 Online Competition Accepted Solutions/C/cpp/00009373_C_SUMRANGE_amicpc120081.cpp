#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
                   int n,l,h;
                   cin>>n>>l>>h;
                   int i,a[1005],x1,j=0;
                   for(i=0;i<n;i++)
                   {
                                   cin>>x1;
                                   if(x1<=h)
                                   {
                                           a[j]=x1;
                                           ++j;
                                   }
                   }
                   sort(a,a+j);
                   int len=j-1;
               //    printf("j: %d, a[0]: %d\n",j,a[0]);
                   if((a[0]>h)||(len<2))
                   cout<<"0"<<endl;
                   else
                   {
                       
                                      int temp=0,k=0,x=0,lpo=len,cnt=0;
                                      int limit=lpo;
                                      while(limit>x)
                                      { x=temp;
                                         temp=x+1;
                                        lpo=limit;
                                         while((a[x]+a[lpo])>h)
                                      --lpo;
                                     k=x+1;
                                      while((x<k)&&(k<lpo))
                                      {
                                      for(k=x+1;k<lpo;k++)
                                      {
                                                          if(((a[x]+a[k]+a[lpo])>=l)&&((a[x]+a[k]+a[lpo])<=h))
                                                                                                              ++cnt;
                                                          else if(((a[x]+a[k]+a[lpo])>h))
                                                          break;
                                      }
                                      k=x+1;
                                      --lpo;
                                       
                                      }
                                      
                                      
                       }
                       cout<<cnt<<endl;
    }}
}
