#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int a[4]={0,0,0,0},k,t,n,i,j=0;
char b[50];
cin>>t;
for(k=t;k>0;k--)
{
cin>>b;
n=strlen(b);
for(i=0;i<n;i++)
{
switch(b[i])
{
case 'W':
  a[0]++;
  break;
case 'R':
  a[1]++;
  break;
case 'B':
  a[2]++;
  break;
case 'G':
  a[3]++;
  break;
}
}
for(i=0;i<4;i++)
{
if((a[i]%2)==1)
j=1;
}
if(j==0)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;

j=0;
for(i=0;i<4;i++)
a[i]=0;
}
return 0;
}
