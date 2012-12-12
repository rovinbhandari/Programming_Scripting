#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define max(a,b) ((a)>(b)?(a):(b))
#define S(a) scanf("%d",&(a))
#define P(a) printf("%d",(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define newline printf("\n")
#define sqr(a) ((a)*(a))
#define SL(a) scanf("%lld",&(a))
#define PL(a) printf("%lld",(a))
#define lli long long int
#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
using namespace std;
int main()
{
    bool flag;
    int tc;
    S(tc);
    string s1;
    int arr[4];
    while(tc--)
    {
        flag=false;
        cin>>s1;
        FOR(i,0,4)
            arr[i]=0;
        FOR(i,0,s1.length())
        {
            if(s1[i]=='R')
                arr[0]++;
            else if(s1[i]=='G')
                arr[1]++;
            else if(s1[i]=='B')
                arr[2]++;
            else if(s1[i]=='W')
                arr[3]++;
         }
         FOR(i,0,4)
         {
             if(arr[i]%2)
                 flag=true;
         }
         if(flag)
              printf("NO\n");
         else
              printf("YES\n");
   }
}