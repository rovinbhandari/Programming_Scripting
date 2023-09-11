#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	char s[50];
	string e[1100];
	int a,b=0,i,j,r=0,g=0,w=0,y[4],x=0,z=0;
	cin>>a;
	for(i=0;i<a;i++)
	{
		cin>>s;
		x=strlen(s);
		for(j=0;j<4;j++)
		{
			y[j]=0;
		}
		for(j=0;j<x;j++)
		{
			if(s[j]=='R')
			y[0]=++r;
			if(s[j]=='G')
			y[1]=++g;
			if(s[j]=='B')
			y[2]=++b;
			if(s[j]=='W')
			y[3]=++w;
		}
		for(j=0;j<4;j++)
		{
			if(y[j]>=2)
			{
			if(y[j]%2==0)
			{
				x++;
			}
			else if(y[j]%2==1)
			{
				z++;
			}
		   }
			else if(y[j]==1)
			{
				z++;
			}
			else if(y[j]==0)
			{
				z=z+0;
			}
		  
	  }
	  if(z==0)
	  e[i]="YES";
	  else
	  e[i]="NO";
	  r=g=b=w=x=z=0;
}
	for(j=0;j<a;j++)
	{
		cout<<e[j]<<endl;
	}
	return 0;
}
