#include<cstdio>
#include<algorithm>
#define MX 300000

using namespace std;

struct T{
      int c0;
      int c1;
      int c01;
} tree[MX];
int a[MX],N;

void initialize(int node,int l,int r)
{
   if(l==r)
    {
        tree[node].c0 = (a[l] == 0) ? 1 : 0;    //if conditions
        tree[node].c1 = (a[l] == 1) ? 1 : 0;
        tree[node].c01 = 1;
    }
   else
    {
       initialize(2*node,l,(l+r)/2);
       initialize(2*node+1,(l+r)/2+1,r);

       tree[node].c0 = tree[2*node].c0+tree[2*node+1].c0;
       tree[node].c1 = tree[2*node].c1+tree[2*node+1].c1;
       tree[node].c01 = max(tree[node].c0, tree[node].c1);

       tree[node].c01 = max(tree[node].c01,tree[2*node].c0 + tree[2*node+1].c1);
       tree[node].c01 = max(tree[node].c01,tree[2*node].c01 + tree[2*node+1].c1);
       tree[node].c01 = max(tree[node].c01,tree[2*node].c0 + tree[2*node+1].c01);
    }
}
T query(int node,int l,int r,int I,int J)
{
   if(I<=l && J>=r)
	   return tree[node];
   int mid = (l+r)/2;
   if(I > mid)
	   return query(2*node+1,mid+1,r,I,J);
   if(J <= mid)
	   return query(2*node,l,mid,I,J);
   else
    {
      T p1,p2,p3;
      p1 = query(2*node,l,mid,I,J);
      p2 = query(2*node+1,mid+1,r,I,J);
   
      p3.c0 = p1.c0+ p2.c0;
      p3.c1 = p1.c1+ p2.c1;
      p3.c01 = max(p3.c0, p3.c1);

      p3.c01 = max(p3.c01, p1.c0 + p2.c1);
      p3.c01 = max(p3.c01, p1.c01 + p2.c1);
      p3.c01 = max(p3.c01, p1.c0 + p2.c01);

      return p3;
    }
}

int main()
{
    char str[200000];
    int i,m,I,J,t;
    scanf("%d", &t);
    while(t--)
    {
	scanf("%d",&N);
	scanf("%s", str);
	for(i=0;i<N;i++) 
	{
	    a[i] = str[i] - '0';
	}
	initialize(1,0,N-1);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
	    scanf("%d%d",&I,&J);
	    printf("%d\n",query(1,0,N-1,I-1,J-1).c01);
	}
    }
return 0;
}

