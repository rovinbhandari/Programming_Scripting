#include<stdio.h>
#include<string.h>
#include<math.h>
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
using namespace std;
#define maX(a,b) (a) > (b) ? (a) : (b)
#define miN(a,b) (a) < (b) ? (a) : (b)
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[55];
		int a=0,b=0,c=0,d=0;
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++)
		{
		    if(s[i]=='R')
		    a++;
		    else if(s[i]=='G')
		    b++;
		    else if(s[i]=='B')
		    c++;
		    else if(s[i]=='W')
		    d++;
		}
		if(a%2==0 && b%2==0 && c%2==0 && d%2==0)
		printf("YES\n");
		else
		printf("NO\n");
	}
return 0;
}
