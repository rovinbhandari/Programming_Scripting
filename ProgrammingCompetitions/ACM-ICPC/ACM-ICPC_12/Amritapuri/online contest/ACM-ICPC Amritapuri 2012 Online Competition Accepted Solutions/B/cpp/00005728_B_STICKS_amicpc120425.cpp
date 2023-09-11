#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
int t,n,m;
cin>>t;
while(t--)
{
long long int diag,max=0,ans=0;
cin>>n>>m;
long long int  l[n];
for(int i=0;i<n;i++)
cin>>l[i];
long long int a[m][3],b[2*m];
for(int i=0;i<m;i++)
{ for(int j=0;j<3;j++)
   cin>>a[i][j];
   diag=sqrt(a[i][0]*a[i][0]+a[i][1]*a[i][1]+a[i][2]*a[i][2]);
   //cout<<diag<<" ";
   if(max<diag)
   max=diag;
}

for(int i=0;i<n;i++)
{
if(l[i]<=max)
ans++;
}
cout<<ans<<endl;
}
return 0;
}

