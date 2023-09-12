// Author : Segment3

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#define LLD long long int
#define MAX 1000000007
using namespace std;

int main()
{
	int i,j,t;
	int r,g,b,w;
	
	cin>>t;
	char str[1001];
	while(t--)
	{ 
		cin>>str;
		r=g=b=w=0;
		for(i=0;str[i]!=0;i++)
		{
			if(str[i]=='R')
				r++;
			else
				if(str[i]=='G')
					g++;
				else
					if(str[i]=='B')
						b++;
					else
						if(str[i]=='W')
							w++;

		}

		if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}



	return 0;

}
