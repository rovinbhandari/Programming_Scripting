#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>
#include <sstream>
#define BUF 4096 // block size on my disk is 4KBs

char ibuf[BUF];
int ipt = BUF;
int read_uint()
{
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    if (ipt == BUF)
    {
        fread(ibuf, 1, BUF, stdin);
        ipt = 0;
        while (ipt < BUF && ibuf[ipt] < '0')
            ipt++;
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0')
    n = (n*10)+(ibuf[ipt++]-'0');
    if (ipt == BUF)
    {
        fread(ibuf, 1, BUF, stdin);
        ipt = 0;
        while (ipt < BUF && ibuf[ipt] >= '0')
            n = (n*10)+(ibuf[ipt++]-'0');
    }
    return n;
}

#define MPI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair
#define SIZE 100005
template <class T>
bool from_string(T& t,
                 const std::string& s,
                 std::ios_base& (*f)(std::ios_base&))
{
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}
/*implementation
bool flag;
int i;
flag=from_string<int>(i, std::string(str), std::hex);
*/
using namespace std;
int main()
{
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  long int i, j, k, n, ans=0,cnt=0;
  long int tc=0;
  scanf("%d",&tc);
  while(tc--)
  {
      long int stick[SIZE] = {0};
      long int a[50002],b[50002] , c[50002], d[50002] ,res = 0;
      long int s = 0;
      long int nst = 0, nbox = 0, m = 0;
      scanf("%li %li",&nst,&nbox);
      for(i = 0;i < nst;i++){
        scanf("%li",&s);
        stick[s] +=1;
      }
      for(i = 0; i < nbox;i++){
          scanf("%li %li %li",&a[i],&b[i],&c[i]);
          ans = (long int)sqrt((a[i]*a[i])+(b[i]*b[i])+(c[i]*c[i]));
          ans = max(ans,max(a[i],max(b[i],c[i])));
          if(m < ans){
              m = ans;
          }
          d[i] = ans;
      }
      //printf("m = %d",m);
      k = stick[i];
      for(i = 1;i <= m;i++){
        stick[i] += stick[i-1];
       // printf("%d %d\n",i,stick[i]);
      }
      printf("%li\n",stick[m]);
  }
  return 0;
}
