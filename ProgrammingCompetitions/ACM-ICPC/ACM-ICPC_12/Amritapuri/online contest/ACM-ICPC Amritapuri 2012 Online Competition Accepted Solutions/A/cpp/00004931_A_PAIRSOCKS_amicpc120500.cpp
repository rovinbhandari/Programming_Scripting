//#include<ctime> 
#include<cstdlib> 
#include<iostream> 
#include<algorithm> 
#include<sstream> 
#include<string> 
#include<vector> 
#include<cmath>
#include<map> 
//#include<conio.h>
using namespace std; 

#define FOR(i,a,b) for(int i = (a); i < (b); ++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it) 
#define pb push_back 
#define all(x) (x).begin(),(x).end() 
#define CLEAR(x,with) memset(x,with,sizeof(x)) 
#define sz size() 


int main()
{
    int t;
    cin>>t;
    
    while(t-- > 0)
    {
              string s;
              cin>>s;
              map<char,int> hash;
              hash.clear();
              for(int i=0;i<s.size();i++)
              {
                      hash[s[i]]++;
              }
              if(hash['R']%2 == 0 && hash['G']%2 == 0 && hash['W']%2 == 0 && hash['B']%2 == 0)
              {
                      cout<<"YES"<<endl;
              }
              else
                      cout<<"NO"<<endl;
    }
    return 0;
    
              
              
}
