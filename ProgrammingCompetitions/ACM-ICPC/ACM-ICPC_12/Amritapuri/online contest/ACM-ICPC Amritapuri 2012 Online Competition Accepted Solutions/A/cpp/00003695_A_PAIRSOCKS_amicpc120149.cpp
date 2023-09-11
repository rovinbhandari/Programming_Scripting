#include<iostream>
using namespace std;
int main()
{
int t,n,len,j;
int r,g,b,w;
string s;
r=g=b=w=0;
cin>>t;
for(int i=0;i<t;i++)
{
cin>>s;
len=s.length();
r=g=b=w=0;
for(j=0;j<len;j++)
{
switch(s[j])
{
case 'R':
r++;
break;
case 'G':
g++;
break;
case 'B':
b++;
break;
case 'W':
w++;
break;
}
}
if(r%2!=0||g%2!=0||b%2!=0||w%2!=0)
cout<<"NO"<<endl;
else
cout<<"YES"<<endl;
}
return 0;
}
