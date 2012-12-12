#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string c;
		int r=0,g=0,b=0,w=0;
		cin>>c;
		for(int i=0;i<c.size();i++)
		{
			if(c[i]=='R')
				r++;
			if(c[i]=='G')
				g++;
			if(c[i]=='B')
				b++;
			if(c[i]=='W')
				w++;
		}
		if( (r%2==0) && (g%2==0) && (b%2==0) && (w%2==0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
