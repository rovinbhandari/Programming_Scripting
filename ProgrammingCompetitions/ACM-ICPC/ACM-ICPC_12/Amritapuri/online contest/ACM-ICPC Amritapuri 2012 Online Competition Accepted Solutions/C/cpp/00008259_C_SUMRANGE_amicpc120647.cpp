#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#define ull unsigned long long int
#define ll long long int
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
 using namespace std;
 int a[1004];

  //for sorting in ascending order.....
int comparea(const void *pVal1, const void *pVal2) {

      int val1 = *(int*)pVal1;

      int val2 = *(int*)pVal2;

      return (val1 - val2);

}




 int cnt(int b,int e,int l)
 {
   //cout<<"in count"<<b<<" "<<e<<" "<<l<<" "<<endl;
   int count1=0;
   while(b<e)
   {
      if(a[b]+a[e]<l)
       {

           count1+=e-b;
           b++;
           //cout<<"ttt"<<b<<" "<<e<<" "<<count1<<endl;
       }
      else
         e--;
   }
return count1;
 }

 int main()
 {
     int t,n,l,h;

     scanf("%d",&t);
     while(t--)
     {
        int sumh=0,suml=0;
        scanf("%d %d %d",&n,&l,&h);
        for(int i=0;i<n;i++)
          cin>>a[i];
        //sort
        qsort(a, n, sizeof(int), comparea);//sorting in ascending order

        for(int i=0;i<n-2;i++)
        {
           suml+=cnt(i+1,n-1,l-a[i]);
           sumh+=cnt(i+1,n-1,h-a[i]+1);
           //cout<<"a"<<i<<" "<<suml<<" "<<sumh<<endl;
        }
        cout<<sumh-suml<<endl;
     }
     return 0;
 }
