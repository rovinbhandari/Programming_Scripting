
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
_ Problem :
_._._._._._._._._._._._._._._._._._._._._.*/

#include<algorithm>
#include<assert.h>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int M[300];

int main()
{

	int t;
	cin >>t;
	while(t--)
	{
		memset(M,0,sizeof(M));
		string A="";
	 	cin >> A;
                int l = A.size();
		for(int i=0;i<l;i++)
		{
			M[A[i]]++;
		}
		if(M['R']%2 == 0 && M['W']%2==0 && M['G']%2==0 && M['B']%2==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	        return 0;
}

