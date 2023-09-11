#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long LL;

int T;
int n;
char s[100];

int main()
{
	scanf("%d",&T);
	
	for(int z=0; z<T; ++z)
	{
		scanf("%s",s);
		
		for(n=0; s[n]!='\0'; ++n);
		
		map<char,int> M;
		for(int i=0; i<n; ++i)
			++M[s[i]];
		
		if(M['R']%2==0 and M['G']%2==0 and M['B']%2==0 and M['W']%2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}