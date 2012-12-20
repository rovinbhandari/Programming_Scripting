//following are pre written include libraries
#include <vector>
#include <queue>
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
#include<string>
using namespace std;
#define F(i,a,n) for(int (i)=a;(i)<(n);(i)++)
#define FE(i,a,n) for(int (i)=a;(i)<=(n);(i)++)
#define sz(x) int((x).size())
#define pb  push_back
#define mp make_pair
#define INI(a,val) memset(a,val,sizeof(a));

int main() 
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        map<char,int> mp;
    mp['B']=0;
    mp['G']=0;
    mp['R']=0;
    mp['W']=0;
    
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]+=1;
        }
        if(mp['B']%2==0 && mp['G']%2==0 && mp['W']%2==0 && mp['R']%2==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        
    }
    return 0;
}
