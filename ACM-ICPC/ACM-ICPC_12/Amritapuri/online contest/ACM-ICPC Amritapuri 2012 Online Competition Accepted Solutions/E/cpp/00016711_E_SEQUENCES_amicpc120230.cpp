#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <climits>
#include <fstream>
#include <algorithm>
#include <queue>
#include <stack>
#define MAX 1000009
#define INF
#define LL long long
using namespace std;


int a[MAX];
struct node
{  int no_0,no_1,optimal;
};

node tree[3*MAX+2];

node fun(node left,node right)
{   node temp;
    temp.no_0 = left.no_0 + right.no_0;
    temp.no_1 = left.no_1 + right.no_1;
    temp.optimal = max ((left.optimal + right.no_1) , (left.no_0+right.optimal) );
    return temp;
}

void build (int i,int lo,int hi)
{	if (lo==hi)
    {   /*
        tree[i]. =(LL) a[hi];
        tree[i].rsum = (LL)a[hi];
        tree[i].msum = (LL)a[hi];
        tree[i].tsum = (LL)a[hi];
        */
        tree[i].no_0 = 0;
        tree[i].no_1 = 0;
        if (a[hi]==0) tree[i].no_0 = 1;
        if (a[hi]==1) tree[i].no_1 = 1;
        tree[i].optimal =1;
        return;

    }

	int mid = (lo+hi)/2;
	build (2*i+1,lo,mid);
	build (2*i+2,mid+1,hi);

	tree[i] = fun (tree[2*i+1],tree[2*i+2]);
}

node query(int i,int lo,int hi,int start ,int end)
{	if (start>hi || end<lo)
    {   node temp;
        temp.no_1 = 0;
        temp.no_0 = 0;
        temp.optimal = 0;
        return temp;
    }
	if (lo>=start && hi<=end) return tree[i];

    int mid = (lo+hi)/2;
	node t1 = query (2*i+1,lo,mid,start,end);
	node t2 = query (2*i+2,mid+1,hi,start,end);
	return fun(t1,t2);
}

int main ()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int T;
    scanf ("%d",&T);
    while (T--)
	{   int n;
        scanf ("%d",&n);
        string s;
        cin>>s;
        for (int i=0;i<n;i++)
            a[i] = s[i]-'0';
        build (0,0,n-1);
        int q;
        scanf("%d",&q);
        int i;int j;
        while (q--)
        {   scanf("%d %d",&i,&j);
            {   node n1 = query(0,0,n-1,i-1,j-1);
                printf("%d\n",n1.optimal);
            }
        }
	}
return 0;
}

