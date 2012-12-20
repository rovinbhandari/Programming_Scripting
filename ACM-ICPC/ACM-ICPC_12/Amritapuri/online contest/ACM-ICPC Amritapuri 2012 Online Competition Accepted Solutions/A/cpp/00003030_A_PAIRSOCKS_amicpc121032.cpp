#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

//pair<int,int> P;
//map<int,int> mymap;
//map<string,int> mymap;
//map<string,int>::iterator it;
//vector<int> vec;
//vector<pair<int,int> > vec2;
//vector<int>::iterator it;
//for(it=mymap.begin();it!=mymap.end();it++)

typedef unsigned long long int ull;
typedef long long int ll;
template <class T> T ABS(const T &x) {return x>0? x:-x;}
template <class T> void SWAP(T &x, T &y) {T z=x; x=y; y=z;}
//const ld PI = 3.14159265358979323846;
//const ld EPSILON = 0.000000000001;
#define all(c) (c).begin(),(c).end()
#define sz 100000
#define INF 2147483647
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define mod 1000000007
#define MAXN 1000010
/*
inline int FAST_IO()
{
    int xxxx;
    char ch;
    int Negativity=0;
    while (((ch=getchar_unlocked()) < 48 || ch > 57) && ch != '-');
    xxxx=0;
    if (ch == '-') Negativity=1;
    else xxxx = ch-48;
    while ((ch=getchar_unlocked()) >= 48 && ch <= 57) xxxx=xxxx*10+ch-48;
    if (Negativity) return -xxxx;
    else return xxxx;
}
*/


int main()
{
	char str[55],ch;
	int c1,c2,c3,c4,tc;
	
	scanf("%d",&tc);
	scanf("%c",&ch);
	while(tc--)
	{
		scanf("%s",str);
		c1=c2=c3=c4=0;
		REP(i,strlen(str))
		{
			if(str[i]=='R')
			c1++;
			else if(str[i]=='G')
			c2++;
			else if(str[i]=='B')
			c3++;
			else if(str[i]=='W')
			c4++;
		}
		if( (c1%2==0) && (c2%2==0) && (c3%2==0) && (c4%2==0) )
		printf("YES\n");
		else printf("NO\n");
		//cout<<c1<<c2<<c3<<c4<<endl;
	}
	return 0;
	
}
