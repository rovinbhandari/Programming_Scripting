#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
int t, n,m,a[50000],b[50000],c[50000],ans[50000];
char q;
cin>>t;
long int l[50000];
int i,j,k;
long long int diag[50000];
for(i=0;i<t;i++)
{ans[i]=0;
cin>>n>>m;
for(j=0;j<n;j++)
cin>>l[j];
sort(l,l+n);
for(j=0;j<m;j++)
{
cin>>a[j]>>b[j]>>c[j];

long long int r=((long long int)(a[j]*a[j])+(long long int)(b[j]*b[j])+(long long int)(c[j]*c[j]));
diag[j]=(long long int)sqrt((long double)r);

}
j=n-1;
sort(diag,diag+m);
while(l[j]>diag[m-1]&&j>=0)
j--;
ans[i]=j+1;

}
for(i=0;i<t;i++)
cout<<ans[i]<<"\n";
}
