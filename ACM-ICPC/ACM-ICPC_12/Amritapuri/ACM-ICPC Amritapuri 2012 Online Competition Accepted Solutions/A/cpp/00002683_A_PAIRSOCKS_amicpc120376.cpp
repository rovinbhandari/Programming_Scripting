#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int hasit[5];
int main()
{

int t;
scanf("%d",&t);
char str[1000];
while(t--)
{
scanf("%s",str);
int l=strlen(str);
for(int i=0;i<4;i++) hasit[i]=0;
for(int i=0;i<l;i++) 
{
	if(str[i]=='R')
	{
		
		hasit[0]++;
	}
	else if(str[i]=='G')
	{
		
		hasit[1]++;
	}
	else if(str[i]=='B')
	{
		
		hasit[2]++;
	}
	else if(str[i]=='W')
	{
		hasit[3]++;
	}
}
int fl=1;
for(int i=0;i<4;i++)
{
	if(hasit[i]%2!=0)
	{
		fl=0;
		break;
	}
}
if(!fl) printf("NO\n");
else printf("YES\n");
}
}