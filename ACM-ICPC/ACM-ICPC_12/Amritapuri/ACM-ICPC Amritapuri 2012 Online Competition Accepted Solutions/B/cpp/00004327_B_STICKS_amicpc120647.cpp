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
     cin>>t;
     while(t--)
     {
         int n,m;
         cin>>n>>m;

         double a[n];

         for(int i=0;i<n;++i)
         cin>>a[i];

         double max=-1;
         double b[m][4];

         for(int i=0;i<m;++i)
         {for(int j=0;j<3;++j)
         {cin>>b[i][j];
         }
         b[i][3]=sqrt(b[i][0]*b[i][0]+b[i][1]*b[i][1]+b[i][2]*b[i][2]);
         if(b[i][3]>max) max=b[i][3];
         }

         int c=0;

         for(int i=0;i<n;++i)
         if(a[i]<=max) c++;

         cout<<c<<endl;

     }
     return 0;
 }
