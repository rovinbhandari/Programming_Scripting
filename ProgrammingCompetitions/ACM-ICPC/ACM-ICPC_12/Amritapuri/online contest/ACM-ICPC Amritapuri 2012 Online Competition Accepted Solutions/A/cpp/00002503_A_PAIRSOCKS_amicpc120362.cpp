#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <climits>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SZ(x) ((int)(x).size())
#define FORV(i,x) FOR(i,0,SZ(x))  
#define DBG(x) cout<<(#x)<<" : "<<(x)<<endl
#define PB push_back
#define ALL(x) x.begin(),x.end()

#define ACC(x) accumulate(ALL(x)) 
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define ROFE(i,a,b) for(int i=(b);i>=(a);i--)
#define MP make_pair
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define PI pair<int,int>
#define PD pair<double,double>
#define F first
#define S second 
#define LL long long
#define ULL unsigned long long

int main()
{
	int cnt[4], cases;
	scanf("%d", &cases);
	char ch = getchar();
	while(cases --)
	{
		memset(cnt, 0, sizeof cnt);
		string str;
		cin >> str;
		FORV(i, str)
			if(str[i] == 'R') cnt[0] ++;
			else if(str[i] == 'G') cnt[1] ++;
			else if(str[i] == 'W') cnt[2] ++;
			else if(str[i] == 'B') cnt[3] ++;
			
		bool flag = true;
		FOR(i, 0, 4) if(cnt[i] & 1) flag = false;
		
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}