#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int t,i,j;
cin>>t;
for(i=0;i<t;i++)
{
int r=0,g=0,b=0,w=0;
char c[51];
cin>>c;
for(j=0;j<strlen(c);j++)
{
if(c[j]=='R') r++;
else if(c[j]=='G') g++;	
else if(c[j]=='B') b++;
else w++;
}
if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
cout<<"YES\n";
else
cout<<"NO\n";
}
return 0;
}