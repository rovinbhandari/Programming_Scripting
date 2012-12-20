#include<iostream>
#include<stdio.h>
using namespace std;
#define MAXN 100003

struct node
{
    int lis;
    int zeros;
    int ones;
};

node tmp;

node M[3*MAXN];
char seq[MAXN];

void build_tree(int start , int i , int j)
{
    if(i == j)
    {
        M[start].lis =  1;
        if(seq[i]=='0')
        {
            M[start].zeros = 1;
            M[start].ones = 0;
        }
        else
        {
            M[start].zeros = 0;
            M[start].ones = 1;
        }
        return;
    }
    int mid = (i + j)/2;

    int lft = 2*start;
    int rgt = 2*start + 1;

    build_tree(lft ,i , mid);
    build_tree(rgt , mid + 1 , j);

    int len1 = M[lft].lis + M[rgt].ones;
    int len2 = M[rgt].lis + M[lft].zeros;
    M[start].lis = max(len1 , len2);
    M[start].ones = M[rgt].ones + M[lft].ones;
    M[start].zeros = M[lft].zeros + M[rgt].zeros;
}

node query(int start ,int b , int e , int i , int j)
{
    if(i > e || j < b) return tmp;
    if( i <= b && e <= j) return M[start];
    int mid = (b + e) /2;

    int lft = 2*start;
    int rgt = lft + 1;
    node lres = query(lft , b , mid , i , j);
    node rres = query(rgt , mid + 1 , e , i , j );

    if(lres.lis == -1) return rres;
    else if(rres.lis == -1) return lres;

    else
    {
        node ret;
        int len1 = lres.lis + rres.ones;
        int len2 = rres.lis + lres.zeros;
        ret.lis = max(len1 , len2);
        ret.ones = rres.ones + lres.ones;
        ret.zeros = lres.zeros + rres.zeros;
        return ret;
    }
}

int main()
{
    int len;
    tmp.lis = -1;
    int t,x,y,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&len);
        scanf("%s" , seq);
        build_tree(1 , 0 , len - 1);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&x , &y);
            node ret = query(1 , 0 , len-1 , x-1 , y-1);
            printf("%d\n", ret.lis);
        }
    }
    return 0;
}
