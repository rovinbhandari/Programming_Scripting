#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<map>
#include<stack>

#define sf scanf
#define pf printf
#define forn(i,a,n) for(i=a;i<n;i++)
#define M 1000000007

using namespace std;
int main()
{
int t,n,h,l,count,i,j,k,sum;
scanf("%d",&t);
while(t--)
{
scanf("%d%d%d",&n,&l,&h);
int a[n];
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
sort(a,a+n);
//for(i=n-1;i>=0;i--)
//{
// if(a[i]<=h)
// break;
//}
//n=i;
sum=0;
count=0;
for(i=n-1;i>=2;i--)
{
sum+=a[i];
if(sum<=h)
{
for(j=i-1;j>=1;j--)
{
sum+=a[j];
if(sum<=h)
{
for(k=j-1;k>=0;k--)
{
sum+=a[k];
if(sum<=h && sum >=l)
{
count++;
}
 if(sum<l)
 {
          sum-=a[k];
          break;
 }
sum-=a[k];
}
}
sum-=a[j];
}
}
sum=0;
}
cout<<count<<endl;
}
return 0;
}

