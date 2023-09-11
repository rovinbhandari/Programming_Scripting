#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	int T,l;
	char c[50];
	int r=0,g=0,b=0,w=0;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		r=0;g=0;b=0;w=0;
	cin>>c;
	l=strlen(c);
	if(l%2!=0)
	cout<<"NO"<<endl;
	else
	{
		for(int j=0;j<l;j++)
		{
			if(c[j]=='R'||c[j]=='r')r++;
			if(c[j]=='G'||c[j]=='g')g++;
			if(c[j]=='B'||c[j]=='b')b++;
			if(c[j]=='W'||c[j]=='w')w++;
		}
		if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
		cout<<"YES"<<endl;
		
		else cout<<"NO"<<endl;
	}
	}
		
}
