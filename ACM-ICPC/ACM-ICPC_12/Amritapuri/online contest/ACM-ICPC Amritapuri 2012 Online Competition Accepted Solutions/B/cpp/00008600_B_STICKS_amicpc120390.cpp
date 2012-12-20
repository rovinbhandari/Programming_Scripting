#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>

#define L long long int
#define U unsigned long long int
using namespace std;

L arr[50010];

main()
{
      int tc;
      cin>>tc;
      while(tc--)
      {

            int n,m;
            cin>>n>>m;
            for(int i = 0;i<n;i++)
            {
                  scanf("%lld", &arr[i]);
            }
            L maxi = 0;
            for(int i = 0;i<m;i++)
            {
                  L a,b,c;
                  scanf("%lld %lld %lld", &a, &b, &c);
                  L x = a*a + b*b + c*c;
                  if(x > maxi)
                        maxi = x;
            }
            int c = 0;
            for(int i = 0;i<n;i++)
            {
                  L x = arr[i]*arr[i];
                  if(x <= maxi)
                        c++;
            }
            printf("%d\n", c);
      }
}
