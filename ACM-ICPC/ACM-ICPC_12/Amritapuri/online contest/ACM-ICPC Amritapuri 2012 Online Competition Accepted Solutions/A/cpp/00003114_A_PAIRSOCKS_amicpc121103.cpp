#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		string p;
		int a[4]={0};
		cin>>p;
		for(int i=0;i<p.length();++i)
		{
			if(p[i]=='R')
				a[0]++;
			else if(p[i]=='G')
				a[1]++;
			else if(p[i]=='B')
				a[2]++;
			else
				a[3]++;
		}
			if((a[0]%2==0 )&&( a[1]%2==0) && (a[2]%2==0) && (a[3]%2==0))
				cout<<"YES\n";
			else
				cout<<"NO\n";

		}
			return 0;
	}

