#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
    int n,l,h,count=0;
    cin>>n>>l>>h;
    int a[n];
    for(int i=0;i<n;i++)
    {
       cin>>a[i];        
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
      if(a[i]>h)break;
      for(int j=i+1;j<n;j++)
      {
        if((a[j]+a[i])>h)break;
        for(int k=j+1;k<n;k++)
        {
          if((a[i]+a[j]+a[k])>=l )
          {      if( a[i]+a[j]+a[k]<=h) count++;
          else
          break;
          }       
        }      
      }       
    }
    cout<<count<<endl;
}
    return 0;
}
