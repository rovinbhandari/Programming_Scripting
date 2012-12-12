#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
int ar,ab,ag,aw,t,i,n,j;
cin>>t;
while(t<0 || t>1000)
{
	cout<<"Cannot b more than 1000";
	cin>>t;
}
char c[50];
char result[t];
for(i=0;i<t;i++)
{	
	cin>>c;
	ar=ab=aw=ag=0;
	n=strlen(c);
	for(j=0;j<n;j++)
	{
		if(c[j]=='R')
			{ar++;}
		else if(c[j]=='W')
			{aw++;}
		else if(c[j]=='G')
			{ag++;}
		else if(c[j]=='B')
			{ab++;}
		else
		{
			cout<<"Invalid input"<<endl;
			exit(0);
		}
	}
	if(ar%2==0 && aw%2==0 && ag%2==0 && ab%2==0)
	{
		result[i]='y';
	}
	else
	{
		result[i]='n';
	}
}
for(i=0;i<t;i++)
{
	if(result[i]== 'y' )
	{
		cout<<"YES";	
		cout<<endl;
	}
	else	
	{
		cout<<"NO";
		cout<<endl;
	}
}
return 0;
}
