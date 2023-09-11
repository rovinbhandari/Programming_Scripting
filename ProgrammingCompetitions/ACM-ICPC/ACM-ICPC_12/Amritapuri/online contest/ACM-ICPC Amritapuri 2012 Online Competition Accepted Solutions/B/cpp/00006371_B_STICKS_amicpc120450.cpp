#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
# define LLU long long int
# define LLD long long double
# define FOR(i,N) for(int i=0;i<(N);i++)
# define pb push_back
using namespace std;
int main()
{
    LLU T,T1,N,M,a,b,c,ct,t,i;
    LLU max,d;
    vector<LLU> len;
    cin>>T; T1=T;
    while(T--){
               //if(T!=T1-1) cout<<endl;
               ct=0;
               cin>>N>>M;
               len.clear(); ct=0; max=0;
               while(N--){
                          cin>>t;
                          len.push_back(t);
                          }
               while(M--){
                          cin>>a>>b>>c;
                          d=(a*a + b*b +c*c);
                          if(d>max) max=d;
                          }
               for(i=0;i<len.size();i++){
                                         if(len[i]*len[i]<=max) ct++;
                                         }
               cout<<ct<<endl;
               }
    return 0;
}
               
               
