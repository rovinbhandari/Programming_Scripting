#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main ()
{ int t=0;
cin>>t;
int n,m;

while(t--)
{
cin>>n>>m;
long long int a[n];
long long int bd=0,l=0,m1=0,h=0,w=0,k=0;

for(int i=0;i<n;i++)
{ cin>>a[i];
 a[i]=a[i]*a[i];
}
for (int i=0;i<m;i++)
{ cin>>l>>w>>h;


long long int z =((l*l)+(h*h)+(w*w));
m1=max(z,m1);
}
for(int i=0;i<n;i++)
{ if(a[i]<=m1)
k++;
}
cout<<k<<endl;
}
return 0;
}
