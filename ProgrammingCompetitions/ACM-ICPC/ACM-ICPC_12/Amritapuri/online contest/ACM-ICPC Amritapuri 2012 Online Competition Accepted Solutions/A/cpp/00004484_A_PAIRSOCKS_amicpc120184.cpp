#include<map>
#include<cstdio>
#include<iostream>
#include<string>
#include<iterator>
using namespace std;
int main()
{
string s;
map<char,int>::iterator it;
int n,i,t,r;
scanf("%d",&t);
while(t--)
{
r=1;
cin>>s;
map<char,int> m;
for(i=0;s[i]!='\0';i++)
m[s[i]]++;
for(it=m.begin();it!=m.end();it++)
if((it->second)&1)
{
r=0;
break;
}
if(r)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}

