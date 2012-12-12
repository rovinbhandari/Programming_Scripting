using namespace std;
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

int main()
{
    int cases,len,i,r,g,b,w;
    string str;
    scanf("%d",&cases);
    getline(cin,str);
    while(cases--)
    {
         getline(cin,str);
         len=str.length();
         r=0;g=0;b=0;w=0;
         
         for(i=0;i<len;i++)
         {
              if(str[i]=='R') r++;
              if(str[i]=='G') g++;
              if(str[i]=='B') b++;
              if(str[i]=='W') w++;
         }
         if( r%2==0 && g%2==0 && b%2==0 && w%2==0) printf("YES\n");
         else printf("NO\n");
    }
    return 0;
}
              
