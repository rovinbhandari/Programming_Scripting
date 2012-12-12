#include<iostream>
using namespace std;
int main()
{
int i,j,k,l,m,n,c1=0,c2=0,c3=0,c4=0;
char s[10000];
cin>>n;
while(n--)
{
cin>>s;
c1=c2=c3=c4=0;
for(i=0;s[i];i++)
{
if(s[i]=='R')
c1++;
if(s[i]=='G')
c2++;
if(s[i]=='B')
c3++;
if(s[i]=='W')
c4++;
}
if(c1%2==0 && c2%2==0 && c3 %2==0 && c4 %2 ==0)
cout<<"YES"<<"\n";
else
cout<<"NO"<<"\n";
}
return 0;
}
