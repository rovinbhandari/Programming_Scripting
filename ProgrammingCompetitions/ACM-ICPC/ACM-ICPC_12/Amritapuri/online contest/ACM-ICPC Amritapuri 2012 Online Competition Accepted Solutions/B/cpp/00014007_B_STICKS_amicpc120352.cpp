#include<iostream>
//#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int t,n,m;
    //scanf("%d",&t);
    cin>>t;
    while(t--)
    {
              cin>>n>>m;
              long long int l[n],le,b,h;
              long long int mx=0,ct=0,body;
              for(int i=0;i<n;i++)
              {
               cin>>l[i];    
              }
              for(int i=0;i<m;i++)
              {        
              //for(int j=0;j<3;j++)
               cin>>le>>b>>h;

               body=((le*le)+(b*b)+(h*h));
               if(body>mx)
               mx=body;
              }
              
              for(int i=0;i<n;i++)
              {
                  if(l[i]*l[i]<=mx)
                  ct++;
              }
              cout<<ct<<"\n";
    }
   //system("pause");
    return 0;
}
