#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX_SIZE 100005

struct data
{
    int a,b,c;
};

int arr[MAX_SIZE];
data tree[3*MAX_SIZE];
int n;

void initi(int node,int left,int right)
{
    if(left==right){
        tree[node].a=tree[node].b=tree[node].c=0;
        if(arr[left]==0) tree[node].a=1;
        else if(arr[left]==1) tree[node].b=1;
        return ;
    }
    int mid=(left+right)/2;
    initi(2*node,left,mid);
    initi(2*node+1,mid+1,right);
    tree[node].a=tree[2*node].a+tree[2*node+1].a;
    tree[node].b=tree[2*node].b+tree[2*node+1].b;
    tree[node].c=max(tree[2*node].a+tree[2*node+1].b,max(tree[2*node].a+tree[2*node+1].c,tree[2*node].c+tree[2*node+1].b));
    //tree[node]=min(tree[2*node],tree[2*node+1]);
    return ;
}

data query(int node,int left,int right,int currLeft,int currRight)
{
    //if(left>currRight||right<currLeft) return NULL;
    if(left==currLeft&&right==currRight) return tree[node];
    int mid=(left+right)/2;
    if(currRight<=mid){
        return query(2*node,left,mid,currLeft,currRight);
    }
    else if(currLeft>mid){
        return query(2*node+1,mid+1,right,currLeft,currRight);
    }
    else {
        data d1 = query(2*node,left,mid,currLeft,mid);
        data d2 = query(2*node+1,mid+1,right,mid+1,currRight);
        data d3;
        d3.a = d1.a+d2.a;
        d3.b = d1.b+d2.b;
        d3.c = max(d1.a+d2.b,max(d1.a+d2.c,d1.c+d2.b));
        return d3;
    }
}

int u,v;

int main()
{
      string str;
      int test,q;
      scanf("%d",&test);
      while(test--)
      {
            scanf("%d",&n);
            cin>>str;
            for(int i=1;i<=n;i++) arr[i]=str[i-1]-'0';
            initi(1,1,n);
            scanf("%d",&q);

            while(q--){
                scanf("%d%d",&u,&v);
                data an = query(1,1,n,u,v);
                int ans = max(an.a,max(an.b,an.c));
                printf("%d\n",ans);
            }
      }
      return 0;
}
