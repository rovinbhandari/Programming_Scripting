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
	int t=0;
	scanf("%d",&t);
	int i,j,k;
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);

		vector <long> l;
		int a,b,c;
		long temp =0;
		double temp1;
		double box=0;
		for(i=0;i<n;i++)
		{

			scanf("%ld",&temp);
			l.push_back(temp);
			 
         }
         
      for(i=0;i<m;i++)
      	{
				scanf("%d %d %d",&a,&b,&c);
				temp1 = pow((a+0.0),2.0)+pow((b+0.0),2.0)+pow((c+0.0),2.0);
				box= max(box,sqrt(temp1));

    }

		sort(l.begin(),l.end());

		int cnt=0;
		for(j=n-1;j>=0;j--)
		{
				if(l[j]<=box)
				{	cnt=j+1;break;}
		}
			
		
		printf("%d\n",cnt);
		}
		
	
	return 0;

	}
	
