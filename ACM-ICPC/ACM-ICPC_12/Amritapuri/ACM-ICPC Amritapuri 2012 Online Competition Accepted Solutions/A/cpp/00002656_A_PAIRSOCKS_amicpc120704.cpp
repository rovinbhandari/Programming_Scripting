#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define SZ(a) a.size()
#define SORT(a) sort(a.begin(),a.end())

using namespace std;

int main()
{
   //freopen("read.txt","r",stdin);
   //freopen("write.txt","w",stdout);

   int test;
   scanf("%d",&test);
   string str;
   int a[4];
   while(test--)
   {    REP(i,4)
                a[i]=0;
        cin>>str;
        int len = str.size();
        REP(i,len)
                if(str[i]=='R')
                        a[0]++;
                else if(str[i]=='W')
                        a[1]++;
                else if(str[i]=='B')
                        a[2]++;
                else a[3]++;
        int flag=0;
        REP(i,4)
                if(a[i]&1)
                        flag=1;
        if(flag)
                printf("NO\n");
        else printf("YES\n");
   }

  return 0;
}
