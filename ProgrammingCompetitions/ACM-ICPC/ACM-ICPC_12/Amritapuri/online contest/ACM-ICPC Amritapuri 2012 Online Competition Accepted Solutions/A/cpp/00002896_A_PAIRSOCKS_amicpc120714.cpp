#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int T,j,i;
char s[60];
int r,g,b,w;
cin>>T;
for(i=0;i<T;i++)
{
r=0,g=0,b=0,w=0;
cin>>s;
for(j=0;j<strlen(s);j++)
{
if(s[j]=='R')
r++;
if(s[j]=='G')
g++;
if(s[j]=='B')
b++;
if(s[j]=='W')
w++;
}
if(r%2 ==0 && g%2==0 && b%2==0 && w%2==0)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
return 0;
}