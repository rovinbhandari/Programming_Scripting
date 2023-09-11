#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
int main()
{
int test,r,b,g,w;
cin>>test;
string str;

int A[test];
for(int j=0;j<test;j++)
{ r=0,b=0,g=0,w=0;
cin>>str;
for(int i=0;i<str.size();i++)
{
if(str[i]=='R')
r++;
else if(str[i]=='G')
g++;
else if(str[i]=='W')
w++;
else if(str[i]=='B')
b++;
}

if(r%2==0 && g%2==0&& w%2==0 && b%2==0)
A[j]=1;
else
A[j]=0;
}
for(int j=0;j<test;j++)
{
if(A[j]==1)
cout<<"YES";
else if(A[j]==0)
 cout<<"NO";
 cout<<endl;
}
return 0;
}

