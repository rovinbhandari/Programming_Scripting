#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
int t,n,a,b,c,d;
string s;
scanf("%d",&t);
while(t--)
{
a=b=c=d=0;
cin>>s;
n=s.length();
for(int i=0;i<n;i++)
{
if(s[i]=='R')
a++;
else if(s[i]=='G')
b++;
else if(s[i]=='B')
c++;
else if(s[i]=='W')
d++;

}
if(a%2==0 && b%2==0 && c%2==0 && d%2==0)
printf("YES\n");
else
printf("NO\n");
}
}
