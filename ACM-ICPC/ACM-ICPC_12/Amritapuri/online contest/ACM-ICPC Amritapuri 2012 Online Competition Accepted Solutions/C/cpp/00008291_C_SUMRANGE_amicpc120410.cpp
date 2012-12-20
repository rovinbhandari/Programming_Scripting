#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              int n,l,h;
            cin>>n>>l>>h;
              int a[n];
              for(int i=0;i<n;i++)
              {
                      scanf("%d",&a[i]);
                      
              }
              sort(a,a+n);
              int dcount=0;
              for(int i=0;i<n-2&&a[i]<=h;i++)
              {
                      for(int j=i+1;j<n-1&&a[i]+a[j]<=h;j++)
                      {
                              
                              for(int k=j+1;k<n&&a[i]+a[j]+a[k]<=h;k++)
                              {
                                      int sum=a[i]+a[j]+a[k];
                                      if(sum<=h&&sum>=l)
                                      dcount++;
                              }
                      }
              }
              
             cout<<dcount<<endl;
    }
    
   // system("pause");
    return 0;
}
