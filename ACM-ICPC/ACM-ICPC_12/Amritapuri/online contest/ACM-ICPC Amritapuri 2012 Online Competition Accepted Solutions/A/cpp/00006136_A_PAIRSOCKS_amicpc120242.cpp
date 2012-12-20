#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
main()
{
int t,ans[1000];
cin>>t;
char c[100];
for(int i=0;i<t;i++)
{
int r=0,g=0,b=0,w=0;
cin>>c;
int len=strlen(c);
for(int j=0;j<len;j++)
{
if(c[j]=='R')
r++;
else if(c[j]=='W')
w++;
else if(c[j]=='G')
g++;
else if(c[j]=='B')
b++;
}
if((r%2==0)&&(b%2==0)&&(g%2==0)&&(w%2==0))
cout<<"YES"<<"\n";
else
cout<<"NO"<<"\n";
}
}
