#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<functional>
#include<iostream>
using namespace std;
int main()
{
int t,r=0,g=0,b=0,w=0;
char c[51];
cin>>t;
for(int q=0;q<t;q++)
{r=0,g=0,b=0,w=0;
cin>>c;
for(int e=0;c[e]!='\0';e++)
{
if(c[e]=='R')
r++;
else

if(c[e]=='B')
b++;
else

if(c[e]=='G')
g++;
else

if(c[e]=='W')
w++;
}
if(r%2==0 && b%2==0 && g%2==0 && w%2==0 )
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
return 0;
};