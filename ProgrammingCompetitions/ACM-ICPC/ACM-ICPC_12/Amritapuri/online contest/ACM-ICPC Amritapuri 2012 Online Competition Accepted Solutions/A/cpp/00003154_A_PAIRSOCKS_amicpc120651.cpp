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
#define SIZE 51
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
  int i, j, k, n, ans=0,cnt=0;
  int tc=0;
  scanf("%d",&tc);
  while(tc--)
  {
    int hash[200] = {0};
    hash['R'] = 0;
    hash['G'] = 0;
    hash['B'] = 0;
    hash['W'] = 0;
    char str[SIZE];
    scanf("%s",&str);
    for(i = 0; str[i] != '\0';i++){
            hash[str[i]] +=1;
    }
   // printf("%d %d %d %d\n",hash['R']%2,hash['G']%2,hash['B']%2,hash['W']%2);
    if(hash['R']%2 == 0 && hash['G']%2 == 0 && hash['B']%2==0 && hash['W']%2==0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
  }
  return 0;
}
