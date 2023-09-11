#include<iostream>
#include<stdio.h>
#define MX 1000000

using namespace std;

int A[1100], arr2 [MX+10];
long long int calculate ;

int main()
{
int t,n,i,j,k;
scanf("%d",&t);
while(t--)
{
int i,j,k,n,l,h,ll,high ;
for(i=1;i<=MX;i++)
arr2 [i]=0;
scanf("%d%d%d",&n,&l,&h);
calculate  = 0;
for(i=1;i<=n;i++)
{
scanf("%d",&A[i]);
arr2 [A[i]]++;
}
for(i=2;i<=MX;i++)
arr2 [i]+=arr2 [i-1];
arr2 [0]=0;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
if(j==i)
continue;
ll=l-A[i]-A[j]-1;
high =h-A[i]-A[j];
if(ll<0)
ll=0;
if(high <0)
high =0;
calculate  += (arr2 [high ]-arr2 [ll]);
if(A[i]>ll && A[i]<=high )
calculate --;
if(A[j]>ll && A[j]<=high )
calculate --;

}
calculate =calculate /6;
printf("%lld\n",calculate );
}
return 0;
}
