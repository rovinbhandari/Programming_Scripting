#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctime>

using namespace std;

int cnt[4];
char s[59];

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%s", s);
		for(int i=0; s[i] != '\0'; i++)
		{
			if(s[i] == 'R')
				cnt[0]++;
			else if(s[i] == 'G')
				cnt[1]++;
			else if(s[i] == 'B')
				cnt[2]++;
			else if(s[i] == 'W')
				cnt[3]++;
		}

		if(cnt[0] % 2 == 0 && cnt[1] % 2 == 0 && cnt[2] % 2 == 0 && cnt[3] % 2 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

