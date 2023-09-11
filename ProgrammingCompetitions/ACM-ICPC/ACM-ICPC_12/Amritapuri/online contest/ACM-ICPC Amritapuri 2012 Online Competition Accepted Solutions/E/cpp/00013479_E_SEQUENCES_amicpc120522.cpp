/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
struct node{
    int zeroes,ones, len;
}TREE[500000];
string str;
int n;
void build_segment_tree(int NODE, int a, int b)
{
    if(a==b)
    {
        TREE[NODE].zeroes = TREE[NODE].ones = 0;
        if(str[a]=='0')
            TREE[NODE].zeroes = 1;
        else
            TREE[NODE].ones = 1;
        TREE[NODE].len = 1;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    TREE[NODE].zeroes=TREE[left].zeroes+TREE[right].zeroes;
    TREE[NODE].ones=TREE[left].ones+TREE[right].ones;
    TREE[NODE].len = max(TREE[left].zeroes+TREE[right].len, TREE[left].len+ TREE[right].ones);
}
node query_segment_tree(int NODE,int a,int b,int x,int y)
{
    if(x<=a && y>=b)return TREE[NODE];
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    node left_query=query_segment_tree(left,a,mid,x,y);
    node right_query=query_segment_tree(right,mid+1,b,x,y);

    node ans;
    ans.zeroes=left_query.zeroes+right_query.zeroes;
    ans.ones=left_query.ones+right_query.ones;
    ans.len = max(left_query.zeroes+right_query.len, left_query.len+ right_query.ones);
    return ans;
}
int a,b;
int main()
{
    in_T
    {
        in_I(n);
        cin>>str;
        build_segment_tree(1, 0,str.length()-1);
        int q;
        in_I(q);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",query_segment_tree(1,0,str.length()-1,a-1,b-1).len);
        }
    }
}
