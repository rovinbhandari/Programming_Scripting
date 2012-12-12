#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include<stdlib.h>
using namespace std;
#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define INF 1000000000
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef long long LL;
int compare (const void * a, const void * b)
{
     return ( *(int*)a - *(int*)b );
}
int main()
{
        int test;
	int n,l,h;
	int i,j,k;
	int array[1000];
	int count1,count2;
	scanf("%d",&test);
	while(test--)
	{

	     scanf("%d%d%d",&n,&l,&h);
	     for(i=0;i<n;i++)scanf("%d",&array[i]);
	     qsort (array,n, sizeof(int), compare);
	     count1=0;
	     for(i=0;i<n-2;i++)
	     {
		 j=i+1;
		 k=n-1;
		 while(j<k)
		 {
		      if(array[i]+array[j]+array[k]>=l)k--;
		      else
		      {
			  count1+=k-j;
			  j++;
		      }
		 }
	     }
	     count2=0;
	     for(i=0;i<n-2;i++)
	     {
		 j=i+1;
		 k=n-1;
		 while(j<k)
		 {
		      if(array[i]+array[j]+array[k]>h)k--;
		      else
		      {
			  count2+=k-j;
			  j++;
		      }
		 }
	     }
	     cout<<count2-count1<<endl;

	}
	return 0;
}
