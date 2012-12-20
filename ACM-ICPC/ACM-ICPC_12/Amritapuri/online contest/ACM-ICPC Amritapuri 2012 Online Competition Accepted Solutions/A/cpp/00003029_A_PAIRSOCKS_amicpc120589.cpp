#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int R=0,G=0,W=0,B=0,i,j,t;
char str[500];
cin>>t;
while(t--)
{
R=0;
G=0;
W=0;
B=0;
cin>>str;
for(i=0;str[i]!='\0';i++)
{
switch (str[i])
{
case 'R':
R++;break;
case 'G':
G++;break;
case 'W':
W++;break;
case 'B':
B++;break;
}
}
if(R%2==0 && G%2==0 && B%2==0 && W%2==0)
cout<<"YES";
else
cout<<"NO";
cout<<"\n";
}
return 0;
}
