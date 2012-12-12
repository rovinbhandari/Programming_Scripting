
/*
 **	Author : Amit Bansal	**
 */

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

#include<vector>
#include<algorithm>
#include<string>


using namespace std;
typedef vector<int> 						VI;

#define fori(i,x,n)						for(int i=x;i<n;i++)
#define ford(i,x,n)						for(int i=x;i>=n;i--)
#define SI 							( {int x;scanf("%d",&x);x;} )

int ar[112345],br[112345],cr[112345];
int M[1000000];

void minitialize(int node, int b, int e)
{
    if (b == e)
	M[node] = cr[b];
    else
    {
	minitialize(2 * node, b, (b + e) / 2);
	minitialize(2 * node + 1, (b + e) / 2 + 1, e);

	M[node] = max(M[2*node],  M[2*node+1]);
    }
    return ;
} 


int mquery(int node, int b, int e, int i, int j)
{
    int p1, p2;
    int p;

    if (i > e || j < b)
	return 0;

    if (b >= i && e <= j)
	return M[node] ;

    p1 = mquery(2 * node, b, (b + e) / 2, i, j);
    p2 = mquery(2 * node + 1, (b + e) / 2 + 1, e, i, j);

    return max(p1,p2);
}


int main()
{
    int t=SI;
    while(t--)
    {
	int n=SI;
	string str;
	cin>>str;
	ar[0]=0;
	fori(i,1,n+1)
	    ar[i]=ar[i-1]+((str[i-1]=='0')?1:0);
	br[n+1]=0;
	ford(i,n,0)
	    br[i] = br[i+1] + ((str[i-1]=='1')?1:0);

	fori(i,1,n+1)
	    cr[i] = ar[i]+br[i];

	minitialize(1,1,n);

	int m=SI;
	int x,y,z;
	for(int i =0;i<m;i++)
	{
	    x=SI,y=SI;
	    z = mquery(1,1,n,x,y)-ar[x-1]-br[y+1];
	    z = max(z, ar[y]-ar[x-1]);
	    z = max(z, br[x]-br[y+1]);
	    cout<<z<<endl;
	}
    }
    return 0;
}
