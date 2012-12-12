
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;

typedef struct n
{
    int nzero;
    int none;
    int lis;
}seg;

class SegmentTree
{
    int size;
    seg *A;
    public:
    SegmentTree(int N)
    {
        int x = (int)(ceil(log2(N)))+1;
        size = 2*(int)pow(2,x);
        A = new seg[size];
        memset(A,-1,sizeof(A));
    }
    ~SegmentTree() { };
    void initialize(int node, int start,int end, int *array)
    {

        if (start==end)
        {
            A[node].nzero=(array[start]==0)?1:0;
            A[node].none = (array[start]==1)?1:0;
            A[node].lis=1;
        }
        else
        {
            int mid = (start+end)/2;
            initialize(2*node,start,mid,array);
            initialize(2*node+1,mid+1,end,array);

            seg left=A[2*node];
            seg right=A[2*node+1];

            A[node].nzero=(left.nzero+right.nzero);
            A[node].none=left.none+right.none;
            A[node].lis=max(left.lis+right.none,max(left.none+right.none,left.nzero+right.lis));
        }
        return ;
    }
    seg query(int node, int start,int end, int i, int j, int *array)
    {
        seg id1,id2;
        seg result;
        seg err;
        err.lis=0;
        err.none=0;
        err.nzero=0;
        if (i>end || j<start)
            return err;

        if (start>=i && end<=j)
            return A[node];

        int mid = (start+end)/2;
        id1 = query(2*node,start,mid,i,j,array);
        id2 = query(2*node+1,mid+1,end,i,j,array);

        result.nzero=(id1.nzero+id2.nzero);

        result.none=id1.none+id2.none;

        result.lis=max(id1.lis+id2.none,max(id1.none+id2.none,id1.nzero+id2.lis));
        return result;
    }
};

int main()
{
    int i,j,N,M;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        char q;
        seg ans;
        scanf("%d",&N);
        int A[N];
        string ss;
        cin >> ss;
        for(i=0;i<ss.size();i++)
            A[i]=ss[i]-'0';
        SegmentTree s(N);
        s.initialize(1,0,N-1,A);
        scanf("%d",&M);
        for(int x=0;x<M;x++)
        {
            scanf("%d%d",&i,&j);
            ans=s.query(1,0,N-1,i-1,j-1,A);
            printf("%d\n",ans.lis);
        }
    }
    return 0;
}


