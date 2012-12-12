#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define cin(n) scanf("%d",&n)
using namespace std;
int arr[1000];
int t,n,l,h,ans=0;
int ls(int s,int e,int num)
{
       int m;
       while(s<e)
       {
                 m=(s+e)/2;
                 if(arr[m]==num)return m;
                 if(arr[m]>num)e=m;
                 else s=m+1;     
       }
       return s;
}
int main()
{
    cin(t);
    int x,y;
    for(;t>0;t--)
    {
                 ans=0;
         cin(n);cin(l);cin(h);
         for(int i=0;i<n;i++)
         {
                 cin(arr[i]);
         }
         
         sort(arr,arr+n);
         for(int i=0;i<n-2;i++)
         {
                 for(int j=i+1;j<n-1;j++)
                 {
                         x=ls(j+1,n-1,l-arr[i]-arr[j]);
                         y=ls(j+1,n-1,h-arr[i]-arr[j]);
                         if(arr[i]+arr[j]+arr[x]<l)continue;
                         if(arr[i]+arr[j]+arr[y]>h)y--;
                         if(y<j)continue;
                         ans+=y-x+1;
                 }
         }
         printf("%d\n",ans);
    }
    
}
