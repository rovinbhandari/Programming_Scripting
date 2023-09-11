  #include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
   int te;
    cin>>te;
    while(te--)
    {
               int ans=-8,n,m;
               scanf("%d",&n);
               scanf("%d",&m);
               long long int arr[n];
               long long int a[m],b[m],c[m];
               double w[m];
               f(i,0,n)
               cin>>arr[i];
               f(i,0,m)
               cin>>a[i]>>b[i]>>c[i];
               f(i,0,m)
               {
                       
                       w[i]=sqrt(a[i]*a[i]+b[i]*b[i]+c[i]*c[i]);
                       
               }
               sort(w,w+m);
               sort(arr,arr+n);
               f(i,0,n)
               {
                       if((double)arr[i]>w[m-1])
                        {
                                 ans=i;
                                 break;       
                        
                        
                        }              
               
               
               }
               if(ans!=-8)
               cout<<ans<<"\n";
               else 
               cout<<n<<"\n";


     }
return 0;
}
