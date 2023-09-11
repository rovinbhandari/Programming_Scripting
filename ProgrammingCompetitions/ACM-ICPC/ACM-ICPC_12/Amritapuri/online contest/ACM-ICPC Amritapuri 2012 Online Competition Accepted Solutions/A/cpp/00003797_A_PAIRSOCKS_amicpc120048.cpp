#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int t,r,g,b,w;
	char sock,socks[50];
	cin>>t;
	while(t>0)
	{
		cin.ignore(256,'\n');
		r=g=w=b=0;
		
			cin>>socks;
			for(int i=0;i<strlen(socks);i++){
			if(socks[i]=='R')
			{
				r=r+1;
				r=r%2;
			}
			if(socks[i]=='G')
			{
				g=g+1;
				g=g%2;
			}
			if(socks[i]=='B')
			{
				b=b+1;
				b=b%2;
			}
			if(socks[i]=='W')
			{
				w=w+1;
				w=w%2;
			}
			}
		if(r==0 && g==0 && b==0 && w==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		t--;
	}
	return 0;
}
