#include<iostream>
using namespace std;
int main()
{
int i;
string a;
int count[4]; 
int t;
cin>>t;
while(t!=0)
{
int flag=0;
for(i=0;i<4;i++)
count[i]=0;
t--;
cin>>a;
for(i=0;i<a.length();i++)
{
if(a[i]=='R')
count[0]++;
if(a[i]=='G')
count[1]++;
if(a[i]=='B')
count[2]++;
if(a[i]=='W')
count[3]++;
}
if(count[0]%2==0)
{
if(count[1]%2==0)
{
if(count[2]%2==0)
{
if(count[3]%2==0)
flag=1;
}
}
}
if(flag==1)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
return 0;
}
