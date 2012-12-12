#include<iostream>
#include<cstdlib>
#include<vector>
#include<climits>
#include<cctype>
#include<map>
#include<list>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<queue>
#include<fstream>
#include<sstream>
#include<set>
#include<iomanip>
#include<bitset>
#include<ctime>
#define L long long int
#define LD long double
#define pi 3.141592653589793238462643383
#define M 1000000007

using namespace std;

int main()
{
    int t,i;
    cin>>t;
    string s;
    while(t--)
    {
              cin>>s;
              int h[4];
              //int h[4];
              for(i=0;i<4;i++)
              h[i]=0;
              for(i=0;i<s.size();i++)
              {
                                     if(s[i]=='R')
                                     h[0]++;
                                     else if(s[i]=='G')
                                     h[1]++;
                                     else if(s[i]=='B')
                                     h[2]++;
                                     else
                                     h[3]++;
              }
              if(h[0]%2==0&&h[1]%2==0&&h[2]%2==0&&h[3]%2==0)
              cout<<"YES\n";
              else
              cout<<"NO\n";
              
              
              
    }
    return 0;
}
