#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std ;
int main()
{
	int TT;
	string a;
	unsigned int w=0,g=0,r=0,b=0;
	//char a[100],*p;
	cin>>TT;
	for(int i=0;i<TT;++i)
	{
		/*gets(a);*/
		cin>>a;
		w=r=g=b=0;
		for(int j=0;/*a[j]!='\n'*/j<(a.length());++j)
		{
			if(a[j]=='W')
				w^=1;
			else if(a[j]=='R')
				r^=1;
			else if(a[j]=='G')
				g^=1;
			else if(a[j]=='B')
				b^=1;
		}
		if(w==0 && r==0 && g==0 && b==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
