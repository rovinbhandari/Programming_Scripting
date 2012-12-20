#include<iostream>
#include<cstdio>
#include<cmath>
#include<utility>
#include<set>
#include<cstring>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

#define FOR(i,n) for(i=0;i<n;i++)
#define REP(i,j,n) for(i=j;i<n;i++)

int main()
{
    int t,i,ans,a[200];
    string str;
    cin>>t;
    while(t--)
    {
              a['R'-'A']=0;a['B'-'A']=0;a['G'-'A']=0;a['W'-'A']=0;
              cin>>str;
              for(i=0;i<str.size();i++)
              {
                  a[str[i]-'A']++;
              }
              if(a['R'-'A']%2==0&&a['B'-'A']%2==0&&a['G'-'A']%2==0&&a['W'-'A']%2==0)
              printf("YES\n");
              else printf("NO\n");
    }
    return 0;
}
