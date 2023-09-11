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
     int zz;
     int zo;
     int oo;
}tree[10000000];
char str[MAX];

void build(int node,int a,int b);
T query(int node,int a,int b,int i,int j);

int main()
{
    T re;
    int cases,n,q,a,b,ans;
    
    scanf("%d",&cases);
    while(cases--)
    {
         scanf("%d",&n);
         scanf("%s",&str);
         build(1,0,n-1);
         scanf("%d",&q);
         while(q--)
         {
              scanf("%d %d",&a,&b);
              re = query(1,0,n-1,a-1,b-1);ans=0;
              ans = max(re.zz,re.zo);
              ans=max(ans,re.oo);
              
              printf("%d\n",ans);
         }
    }
  //  system("pause");
}

void build(int node,int a,int b)
{
    int mid,left,right,zero,one,temp1,temp2,temp3;
    zero=0;one=0;
    
    if(a==b)
    {
         if(str[a]=='0') zero=1;
         else one=1;
         
         tree[node].zz=zero;
         tree[node].zo=0;
         tree[node].oo=one;
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
    if(tree[left].zz && tree[right].oo) temp3 = tree[left].zz + tree[right].oo;
    else temp3=0;
    tree[node].zo = max(max(temp1,temp2),temp3);
   // cout<<a<<" "<<b<<" "<<tree[node].zz<<"  "<<tree[node].zo<<"  "<<tree[node].oo<<endl;
    return;
}
    
T query(int node,int a,int b,int i,int j)
{
     int mid,left,right,temp1,temp2,temp3;
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
         if(p1.zz && p2.oo) temp3 = p1.zz + p2.oo;
         else temp3=0;
         p3.zo = max(max(temp1,temp2),temp3);
         
       //  cout<<a<<" "<<b<<" "<<p3.zz<<"  "<<p3.zo<<"  "<<p3.oo<<endl;
         return p3;
     }
}
