#include<iostream>
#include<cstdio>
using namespace std;
int main()
{

char c[51];

    int i,j,k,t,rc,bc,gc,wc;
cin>>t;
while(t--)
{rc=0;gc=0;wc=0;bc=0;
scanf("%s",&c);
for(i=0;c[i]!='\0';i++)
{if(c[i]=='R')
rc++;
if(c[i]=='W')
wc++;
if(c[i]=='B')
bc++;
if(c[i]=='G')
gc++;
}
if((rc%2==0)&&(wc%2==0)&&(gc%2==0)&&(bc%2==0))
cout<<"YES\n";
else
cout<<"NO\n";
}

return 0;
}

