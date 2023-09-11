using namespace std;
#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef long long ll; 
typedef pair<int,int> pii; 
#define FOR(i,n) for (int i = 0; i < n; i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define MP make_pair
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
#define split(str) {vs.clear();istringstream ss(str);while(ss>>(str))vs.push_back(str);}
#define PI 3.141592653589793
int main()
{
  int t;
  sf(t);
  while(t--)
  {
    string s;
    cin>>s;
    map<char,int> m;
    m['R']=0;
    m['G']=0;
    m['B']=0;
    m['W']=0;
    FOR(i,s.size())
    {
      m[s[i]]++;
    }
    if(m['R']%2==0&&m['G']%2==0&&m['B']%2==0&&m['W']%2==0)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}