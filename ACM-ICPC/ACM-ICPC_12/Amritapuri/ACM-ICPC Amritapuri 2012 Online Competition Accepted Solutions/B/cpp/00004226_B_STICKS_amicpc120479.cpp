#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int arr[100000];
int main()
{
    long long int t,n,m,max=0,temp,x,y,z,flag=0;
    scanf("%lld",&t);
    while(t--)
    {scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(int i=0;i<m;i++)
    {scanf("%lld%lld%lld",&x,&y,&z);
    x=(x*x+y*y+z*z);
    temp=sqrt(x);
    if(temp>max)max=temp;}
    for(int i=0;i<n;i++)
    if(arr[i]<=max)flag++;
    printf("%lld\n",flag);
    flag=max=0;
              }
              return 0;
              }
