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

main()
{
      int tc;
      cin>>tc;
      while(tc--)
      {
            char arr[60];
            scanf("%s", &arr);
            int l = strlen(arr);
            if(l&1)
            {
                  printf("NO\n");
            }
            else
            {
                  int r = 0, g = 0, w = 0, b=0;
                  for(int i = 0;i<l;i++)
                  {
                        switch(arr[i])
                        {
                              case 'R':r++;
                              break;
                              case 'B':b++;
                              break;
                              case 'G':g++;
                              break;
                              case 'W':w++;
                              break;
                        }
                  }
                  if(r&1 || b&1 || g&1 || w&1)
                        printf("NO\n");
                  else
                        printf("YES\n");

            }
      }
}
