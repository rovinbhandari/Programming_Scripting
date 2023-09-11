#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              int count=0,sum=0,sum1=0,temp;
              int n,l,h;
              cin>>n>>l>>h;
              int a[n];
              for(int i=0;i<n;i++)
              {
                      cin>>a[i];
              }
              sort(a,a+n);
              
              for(int i=0;i<n-2&&a[i]<=h;i++)
              {
                      for(int j=i+1;j<n-1&&a[i]+a[j]<=h;j++)
                      {  
                              for(int k=j+1;k<n && a[i]+a[j]+a[k]<=h;k++)
                              {
                                      sum=a[i]+a[j]+a[k];
                                      if(sum<=h && sum>=l)
                                      count++;
                              }
                      }
                      
              }
              cout<<count<<endl;
    }
    return 0;
}
