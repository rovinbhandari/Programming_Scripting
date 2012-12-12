#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>

#define INF (1<<30)

#define reset(x) memset(x, 0 , sizeof(x))

using namespace std;

int A[1024];

int main()
{
      //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
      int T,N,L,H,sum,low,high,mid,start,end,diff;
      scanf("%d",&T);
      
      while(T--)
      {
           scanf("%d%d%d",&N,&L,&H);

           for(int i=0;i<N;i++)  scanf("%d",&A[i]);
           sort(A,A+N);

           int total=0;
           for(int i=0;i<N;i++)
           for(int j=0;j<N;j++) {
                   if(i==j) continue;
                   int k=0;
                   int akh=H-A[i]-A[j], akl=L-A[i]-A[j];

                   low=0;high=N-k-1;
                   while(low<=high)
                   {
                        mid=(low+high)/2;
                       // cout<<mid<<"**"<<endl;
                        if(akl<=A[mid]) high=mid-1;
                        else low=mid+1;
                   }
                   start=high;
                   
                   low=0;high=N-k-1;
                   while(low<=high)
                   {
                        mid=(low+high)/2;
                      //  cout<<mid<<"++"<<endl;
                        if(akh>=A[mid]) low=mid+1;
                        else high=mid-1;
                   }
                   end=high;
                   diff=end-start;
                   if(i>start && i<=end) diff--;
                   if(j>start && j<=end) diff--;
                   total+=diff;
           }
           total/=6;
           printf("%d\n",total);      
      }
   //   system("pause");
    return 0;
}

