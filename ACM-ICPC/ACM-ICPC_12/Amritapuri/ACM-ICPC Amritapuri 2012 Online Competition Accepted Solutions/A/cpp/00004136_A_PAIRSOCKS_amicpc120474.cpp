#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
int main()
{
	char str[100];
	int t,a,i,res,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		res=0;
		a=0;
		b=0;
		c=0;
		d=0;
		scanf("%s",&str);
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]=='R')
				a^=1;

			if(str[i]=='G')
				b^=1;
			if(str[i]=='W')
				c^=1;
			if(str[i]=='B')
				d^=1;
			res=res^a;
		}
		if(a==0&&b==0&&c==0&&d==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
