#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>


//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#define ll long long
#define ull unsigned long long
#define mod 1000000007ll
#define fill(x) memset(x,0,sizeof x)
#define inf (ll)1e18
#define iinf (int)1e9

using namespace std;


int main()
{
	char input[60];
	int t=0;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		
		gets(input);
		int l = strlen(input);

		map <char,int> mymap;
		for(int i=0;i<l;i++)
		{
			mymap[input[i]]++;
		}
		map<char,int>::iterator it;
		bool chk=true;
		for(it=mymap.begin();it!=mymap.end();it++)
		{
                               
			if((it->second)%2==0)
				chk&=true;
			else
				chk&=false;
		}
		if(chk)
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	return 0;
}
