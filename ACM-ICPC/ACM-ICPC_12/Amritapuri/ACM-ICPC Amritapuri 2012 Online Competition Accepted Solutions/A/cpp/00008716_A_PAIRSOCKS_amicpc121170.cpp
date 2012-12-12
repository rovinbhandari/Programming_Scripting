#include <cstdio>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;

int main()
{
	int T; 
	cin>>T;
	if(!(T>0&&T<1001))
	return 0;
	for(int kase = 1; kase <= T; kase++)
	{
		char c[50];
		cin>>c;
		int ln=strlen(c);
		if(ln>50) return 0;
		int bc=0,rc=0,wc=0,gc=0;
		for(int i=0; i<ln; i++)
		{
			if(c[i]=='W') wc++;
			if(c[i]=='B') bc++;
			if(c[i]=='G') gc++;
			if(c[i]=='R') rc++;
		
		}
		if(((bc%2)==0)&&((wc%2)==0)&&((gc%2)==0)&&((rc%2)==0))
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}
