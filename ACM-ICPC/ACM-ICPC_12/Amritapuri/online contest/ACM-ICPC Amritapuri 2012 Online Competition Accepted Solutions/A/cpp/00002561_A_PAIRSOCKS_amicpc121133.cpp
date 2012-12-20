#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;

#define MOD 1000000007ll

int main()
{
	int t;
	cin>>t;
	while( t-- )
	{
		string s;
		cin>>s;
		vector <int> count(1000,0);
		for( int i=0;i<s.size();i++)
			count[s[i]]++;
		int valid = 1;
		for( int i=0;i<1000;i++)
		{
			if( count[i]%2 == 1 )
				valid = 0;
		}
		if( valid == 0 )
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}

			
	

