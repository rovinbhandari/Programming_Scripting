





#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<cctype>
#include<string>
#include<vector>
#include<sstream>
#include<iterator>
#include<numeric>
#include<cmath>
#include<cstring>
#include<complex>
#include<cstdlib>
#include<climits>
#define RFOR(i,a,b) for(int i=a; i > b; i--)
#define FOR(i,a,b) for(int i=a; i < b;i++)
#define PB push_back
#define BN begin()
#define ED end()
#define RN rbegin()
#define RD rend()
#define PF push_front
#define BP pop_back
#define FP pop_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
/*#define tr(container, it) \ 
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //to travrse any container
  #define present(container, element) (container.find(element) != container.end()) //to check any element present or not
 #define cpresent(container, element) (find(all(container),element) != container.end())      //same as above but use in vector*/
#define VV(X) vector< vector< X > > 
#define PIB(X) pair<IT(X),bool>
#define SQ ((x)*(x))
#define El() cout<<endl;
typedef long long LL;typedef unsigned long long ULL;
#define istringstream ISS;
#define stringstream SS;
 using namespace std;
typedef vector<int> VI ;
typedef pair <int,int> PII;
typedef vector< PII > VPII;

using namespace std;
int main()
{
	long cas;
	cin >> cas;
	while(cas-- > 0)
	{//cin >> n;
	string s;
	//for(int i=0;i<n;i++)
	//{
	cin >> s;
	//}	
	int ct[4]={0,0,0,0};
	int l=s.size();
	FOR(i,0,l)
	{
	if(s[i] == 'R')
	ct[0]+=1;
	else if(s[i] == 'G')
	ct[1]+=1;
	else if(s[i] == 'B')
	ct[2]+=1;
	else if(s[i] == 'W')
	ct[3]+=1;
	}
	int f=1;
	FOR(i,0,4)
	if(ct[i] %2 != 0)
	{f=0;break;
	}
	if(f==1)
	cout<<"YES";
	else cout<<"NO";
	 cout<<endl;
//	EL();
	}

	return 0;
}
