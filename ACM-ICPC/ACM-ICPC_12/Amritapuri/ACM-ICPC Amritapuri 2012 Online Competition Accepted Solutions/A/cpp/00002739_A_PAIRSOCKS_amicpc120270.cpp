//Author : aitch_nu

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<set>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r=0,g=0,b=0,w=0;
		char str[10000];
		scanf("%s",str);
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]=='R')r++;
			if(str[i]=='G')g++;
			if(str[i]=='B')b++;
			if(str[i]=='W')w++;
		}
		if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
