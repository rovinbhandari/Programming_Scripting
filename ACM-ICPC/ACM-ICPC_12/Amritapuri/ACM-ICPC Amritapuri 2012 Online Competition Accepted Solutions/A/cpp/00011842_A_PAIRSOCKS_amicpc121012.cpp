#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
	int i,a,j;
	cin>>a;
	char str[1000][50];
	getchar();
	for (i=0;i<a;i++)
	{
	gets(str[i]);
	int r,g,b,w;
	int flag;
	
//	for (i=0;i<a;i++)
	{
		r=0;g=0,b=0,w=0;
		flag=1;
		for(j=0;j<strlen(str[i]);j++)
		{
			if (str[i][j]=='R')
				r+=1;
			if (str[i][j]=='G')
				g+=1;
			if (str[i][j]=='B')
				b+=1;
			if (str[i][j]=='W')
				w+=1;
		}
		if(r%2!=0)
			flag=0;
		if(g%2!=0)
			flag=0;
		if(b%2!=0)
			flag=0;
		if(w%2!=0)
			flag=0;
		if(flag==0)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}	return 0;
}	
