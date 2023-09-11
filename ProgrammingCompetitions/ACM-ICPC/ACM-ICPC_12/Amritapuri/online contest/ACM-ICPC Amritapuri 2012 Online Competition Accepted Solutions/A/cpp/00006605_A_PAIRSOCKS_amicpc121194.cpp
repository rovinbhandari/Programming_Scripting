#include<iostream>
using namespace std;
int main()
{int t;
int n,i,j,b,g,r,w;
b=0;g=0;r=0;w=0;
string p[1000];
string s;
cin>>t;
for(j=0;j<t;j++)
{b=0;g=0;r=0;w=0;
cin>>s;
i=0;
while(s[i]!='\0')
{
if(s[i]=='B')
b++;
if(s[i]=='G')
g++;
if(s[i]=='R')
r++;
if(s[i]=='W')
w++;
i++;
}
if(b%2==0 && g%2==0 && r%2==0 && w%2==0)
p[j]="YES";
else
p[j]="NO";
}
for(j=0;j<t;j++)
cout<<p[j]<<"\n";
}