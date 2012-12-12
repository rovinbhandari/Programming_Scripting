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
typedef struct node
{
    int l00,l01,l11,maxx;
}
node;
//The array holding the segment tree just like the heap
struct node tree[1000000];
char a[1000000];

//this is the updation function you need to call whenever you need to fill the values of the node depending upon the child nodes.
//For example in the case of RMQ problem it would just consist of two lines comparing the child nodes values and puttting the minimum in the parent node
//passed here as pointer.
void update_val(node left,node right,node *p)
{
    p->l00 = max(max(left.l00+right.l00,left.l00),right.l00);
    p->l01=0;
    if(left.l01!=0)
    p->l01=max(p->l01,left.l01+right.l11);
    if(left.l00!=0&&right.l11!=0)
    {
          p->l01=max(p->l01,left.l00+right.l11);
    }
    if(right.l01!=0)
    {
        p->l01=max(p->l01,left.l00+right.l01);

    }


    p->l11  = max(left.l11 + right.l11,max(left.l11,right.l11));
    p->maxx = max(p->l00 , max(p->l01,p->l11));
}

void build(int mark,int b,int e)
{
    int mid = (b+e)/2;
    if(b==e)
    {
        if(a[b-1]=='1')
        {
           // cout<<b<<" "<<"\n";
        tree[mark].l00 =0;
        tree[mark].l01 =0;
        tree[mark].l11 = 1;
        tree[mark].maxx  =1;
        }
        else
        {
           // cout<<b<<"ds\n";
        tree[mark].l00 =1;
        tree[mark].l01 =0;
        tree[mark].l11 = 0;
        tree[mark].maxx  =1;
        }

        return;
    }
    build(mark*2,b,mid);
    build(mark*2+1,mid+1,e);
    //In topcoder where minimum is found and parent  value is updated..such tasks are now done in update_val fucntion because a node  may have more
    //than one value to be updated(like in this case) depending on its child values.
    update_val(tree[mark*2],tree[mark*2+1],&tree[mark]);
}

//for query ...simple
node query(int mark,int b,int e,int i,int j)
{
    node count;
    int mid = (b+e)/2;
    if(b==i&&e==j)
        count = tree[mark];
    else if(j<=mid)
        count = query(mark*2,b,mid,i,j);
    else if(i>mid)
        count = query(mark*2+1,mid+1,e,i,j);
    else
        update_val(query(mark*2,b,mid,i,mid),query(mark*2+1,mid+1,e,mid+1,j),&count);
    return count;
}

int main()
{
     int t;
     scanf("%d",&t);
     while(t--)
     {
     int n,q,lo,i,hi;
    scanf("%d",&n);
        scanf("%s",a);
        //printf("%s\n",a);
    build(1,1,n);
    scanf("%d",&q);
  /*  for(int i=1;i<=15;i++)
    cout<<tree[i].l00<<" "<<tree[i].l11<<" "<<tree[i].l01<<"\n";*/
    while(q--)
    {
        scanf("%d %d",&lo,&hi);
        printf("%d\n",query(1,1,n,lo,hi).maxx);
    }
  }
    return 0;
}
