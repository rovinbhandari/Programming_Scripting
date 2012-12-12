#include<iostream>
#include<set>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std ;
#define INF (int)1e9

/*
 * If the index of the last 0 in the range [a...b] is m,
 * the number of 0s = p0[m] - p0[a - 1]
 * the number of 1s = p1[b] - p1[m]
 * 
 * So the goal is to maximize p0[m] - p0[a - 1] + p1[b] - p1[m]
 *
 * If there are no 0s in the subsequence, just count the number
 * of 1's in the range and choose the maximum of the two.
 */

#define MAXN 100002
int n,p0[MAXN],p1[MAXN] ;
char s[MAXN] ;

int b[MAXN] ;
int t[4 * MAXN] ;
void create(int k,int low,int high)
{
 if(low == high)
 {
  t[k] = b[low] ;
  return ;
 }
 int mid = (low + high) / 2 ;
 create(2 * k,low,mid) ;
 create(2 * k + 1,mid + 1,high) ;
 t[k] = max(t[2 * k], t[2 * k + 1]) ;
}

int query(int k,int low,int high,int qlow,int qhigh)
{
 if(low > qhigh || qlow > high) return -INF ;
 if(low >= qlow && high <= qhigh) return t[k] ;
 int mid = (low + high) / 2 ;
 int ret1 = query(2 * k,low,mid,qlow,qhigh) ;
 int ret2 = query(2 * k + 1,mid + 1,high,qlow,qhigh) ;
 return max(ret1,ret2) ;
}

#define SLOW 0

int main()
{
 int runs ;
 scanf("%d", &runs) ;
 while(runs--)
 {
  scanf("%d", &n) ;
  while(n < 1 || n > 100000) ;

  scanf("%s", s) ;
  while(strlen(s) != n) ;
  
  for(int i = 1;i <= n;i++)
  {
   p0[i] = p0[i - 1] + (s[i - 1] == '0' ? 1 : 0) ;
   p1[i] = p1[i - 1] + (s[i - 1] == '1' ? 1 : 0) ;
   b[i] = p0[i] - p1[i] ;
  }
  
  create(1,1,n) ;
  
  int q ;
  scanf("%d", &q) ;
  while(q < 1 || q > 100000) ;
  while(q--)
  {
   int a,b ;
   scanf("%d%d", &a, &b) ;
   while(a < 1 || a > b || b > n) ;
   
   if(SLOW)
   {
    int ret = p1[b] - p1[a - 1] ;
    for(int i = a;i <= b;i++)
     ret = max(ret,p0[i] - p0[a - 1] + p1[b] - p1[i]) ;
    printf("%d\n",ret) ;
    continue ;
   }
   
   int ret = p1[b] - p0[a - 1] + query(1,1,n,a,b) ; 
   ret = max(ret,p1[b] - p1[a - 1]) ;
   printf("%d\n",ret) ;
  }
 }
 return 0 ;
}
