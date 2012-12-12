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

# define MAX 1000000

struct T
{
     long long zz;
     long long zo;
     long long oo;
}tree[10000000];

char str[MAX];

void build(long long node,long long a,long long b);
T query(long long node,long long a,long long b,long long i,long long j);

int main()
{
    T re;
    long long cases,n,q,a,b,ans;
    
    scanf("%lld",&cases);
    while(cases--)
    {
         scanf("%lld",&n);
         scanf("%s",&str);
         build(1,0,n-1);
         scanf("%lld",&q);
         while(q--)
         {
              scanf("%lld %lld",&a,&b);
              re = query(1,0,n-1,a-1,b-1);ans=0;
              ans = max(re.zz,re.zo);
              ans=max(ans,re.oo);
              
              printf("%lld\n",ans);
         }
    }
  //  system("pause");
}

void build(long long node,long long a,long long b)
{
    long long mid,left,right,zero,one,temp1,temp2,temp3;
    zero=0;one=0;
    
    if(a==b)
    {
         
         tree[node].zz=0;
         tree[node].zo=0;
         tree[node].oo=0;
         
         if(str[a]=='0') tree[node].zz=1;
         else tree[node].oo=1;    
        // cout<<a<<" "<<b<<" "<<tree[node].zz<<"  "<<tree[node].zo<<"  "<<tree[node].oo<<endl;
         return;
    }
    
    mid=(a+b)/2;
    build(2*node,a,mid);
    build( (2*node)+1,mid+1,b);
    
    left=2*node;
    right=(2*node)+1;
    
    tree[node].zz = tree[left].zz + tree[right].zz;
    tree[node].oo = tree[left].oo + tree[right].oo;
    
    temp1 = tree[left].zz + tree[right].zo;
    temp2 = tree[left].zo + tree[right].oo; 
    if(tree[left].zz!=0 && tree[right].oo!=0) temp3 = tree[left].zz + tree[right].oo;
    else temp3=0;
    tree[node].zo = max(max(temp1,temp2),temp3);
   // cout<<a<<" "<<b<<" "<<tree[node].zz<<"  "<<tree[node].zo<<"  "<<tree[node].oo<<endl;
    return;
}
    
T query(long long node,long long a,long long b,long long i,long long j)
{
     long long mid,left,right,temp1,temp2,temp3;
     if(i<=a && j>=b)
     {
        // cout<<a<<" "<<b<<" "<<tree[node].zz<<"  "<<tree[node].zo<<"  "<<tree[node].oo<<endl;
          return tree[node];
     }
          
     mid=(a+b)/2;
     left=2*node;
     right=(2*node)+1;
     
     if(j<=mid)
          return query(left,a,mid,i,j);
     else if(i>mid)
          return query(right,mid+1,b,i,j);
     
     else
     {
         T p1,p2,p3;
         p1=query(left,a,mid,i,j);
         p2=query(right,mid+1,b,i,j);
         
         p3.zz = p1.zz + p2.zz;
         p3.oo = p1.oo + p2.oo;
    
         temp1 = p1.zz + p2.zo;
         temp2 = p1.zo + p2.oo; 
         if(p1.zz!=0 && p2.oo!=0) temp3 = p1.zz + p2.oo;
         else temp3=0;
         p3.zo = max(max(temp1,temp2),temp3);
         
       //  cout<<a<<" "<<b<<" "<<p3.zz<<"  "<<p3.zo<<"  "<<p3.oo<<endl;
         return p3;
     }
}
