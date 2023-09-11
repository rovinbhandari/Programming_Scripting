#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#define ll long long int
using namespace std;
int main()
{
	int t,i;
	char s[51];
	int r,g,b,w;
	cin>>t;
	while(t--)
	{
		scanf("%s",s);
		r=g=b=w=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='R' && r==0)
			r=1;
			else if(s[i]=='R' && r==1)
			r=0;
			if(s[i]=='G' && g==0)
			g=1;
			else if(s[i]=='G' && g==1)
			g=0;
			if(s[i]=='B' && b==0)
			b=1;
		 	else if(s[i]=='B' && b==1)
			b=0;
			if(s[i]=='W' && w==0)
			w=1;
			else
			if(s[i]=='W' && w==1)
			w=0;
		}
		if(r==0 && g==0 && b==0 && w==0)
		cout<<"YES\n";
		else 
		cout<<"NO\n";
	}
	return 0;
}
