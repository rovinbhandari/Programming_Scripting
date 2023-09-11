#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
int n;
int i,j;
int r=0,g=0,b=0,w=0;
cin>>n;
char s[60];
for(i=0;i<n;i++)
{
cin>>s;
for(j=0;j<strlen(s);j++)
{
switch(s[j])
{
case 'R':r++; break;
case 'G':g++;break;
case 'B':b++;break;
case 'W':w++;break;
}
}
if (r%2==0 && g%2==0 && b%2==0 && w%2==0)
puts("YES");
else
puts("NO");
r=0;
g=0;
b=0;
w=0;
}
return 0;
}
