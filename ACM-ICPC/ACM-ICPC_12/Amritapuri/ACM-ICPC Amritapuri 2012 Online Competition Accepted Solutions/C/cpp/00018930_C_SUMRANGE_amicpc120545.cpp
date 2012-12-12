#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
int A[1001];
 //int b[50001];
int main()
{
      //freopen("input","r",stdin);
  //freopen("output","w",stdout);
  //int t,l,h,n;
  //int res=0,cnt=0;
  //vector<int> v;
    int t;
    cin>>t;
    while(t--)
    {
              int n,L,H;
              scanf("%d%d%d",&n,&L,&H);
              for(int i=0;i<n;i++)
              cin>>A[i];
              sort(A,A+n);

       int l, r,count=0;

         for(int i=0; i<n-2;i++){
        l = i + 1;
        r = n-1;
        while (l<r)
        {
            if (A[i] + A[l] + A[r]<=H)
                {
                     count+=(r-l);
                     l++;
                }
            else
                r--;
        }
    }
       for(int i=0; i<n-2;i++){
        l = i + 1;
        r = n-1;
        while (l<r)
        {

            if (A[i] + A[l] + A[r]<L)
                {
                     count-=(r-l);
                     l++;
                }
            else
                r--;
        }
 }
    printf("%d\n",count);
}
return 0;
}
