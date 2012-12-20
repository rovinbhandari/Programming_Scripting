#include<iostream>
#include<string.h>
using namespace std;

int t, r, g, b, w;
char sock[100];

int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	cin.get();
	while(t)
	{
		--t;
		cin.getline(sock, 100);
		r=g=b=w=0;
		for(int i=0; i<strlen(sock); ++i)
		{
			if(sock[i]=='R')
				++r;
			else if(sock[i]=='G')
				++g;
			else if(sock[i]=='B')
				++b;
			else
				++w;
		}
		if(b%2==0 && r%2==0 && w%2==0 && g%2==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
