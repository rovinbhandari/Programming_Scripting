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
#include <string>
#include <cstring>
#define ull unsigned long long int
#define ll long long int
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
 using namespace std;

 int main()
 {
     int t;
     string s;
     cin>>t;
     while(t--)
     {
        cin>>s;
        int a[4];
        a[0]=a[1]=a[2]=a[3]=0;
        for(int i=0;i<s.length();i++)
        {
           if(s[i]=='R')
             a[0]++;
           else if(s[i]=='G')
             a[1]++;
           else if(s[i]=='W')
             a[2]++;
           else
             a[3]++;
        }
        if(a[0]%2||a[1]%2||a[2]%2||a[3]%2)
          cout<<"NO\n";
        else
          cout<<"YES\n";
     }
     return 0;
 }
