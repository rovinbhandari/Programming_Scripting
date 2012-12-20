
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;
int tree[300010];
int ar3[100010];

void frst(int cur,int s,int e)
{
	if (s==e)
	{
		tree[cur]=ar3[s];
		return ;
	}
	int m=(s+e)/2;
	frst(2*cur,s,m);
	frst(2*cur+1,m+1,e);
	tree[cur]=max(tree[2*cur],tree[2*cur+1]);
}

int query(int cur,int s,int e,int fs,int fe)
{
	if (fs>e || fe<s)
		return 0;
	if (s>=fs && e<=fe)
		return tree[cur];
	int m=(s+e)/2;
	int v1=query(2*cur,s,m,fs,fe);
	int v2=query(2*cur+1,m+1,e,fs,fe);
	return max(v1,v2);
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		
		int n;
		scanf("%d",&n);
		char s[100010];
		scanf("%s",s);
		int ar1[100010],ar2[100010];
		memset(tree,0,sizeof tree);
		memset(ar1,0,sizeof ar1);
		memset(ar2,0,sizeof ar1);
		memset(ar3,0,sizeof ar1);
		ar1[0]=(s[0]=='0')?1:0;
		for (int i=1;i<n;i++) {
			if (s[i]=='0') ar1[i]=ar1[i-1]+1;
			else ar1[i]=ar1[i-1];
		}
		ar2[n]=0;
		ar2[n-1]=(s[n-1]=='1')?1:0;
		for (int i=n-2;i>=0;i--) {
			if (s[i]=='1') ar2[i]=ar2[i+1]+1;
			else ar2[i]=ar2[i+1];
		}
		ar3[0]=(s[0]=='1')?ar2[0]:0;
		for (int i=1;i<n;i++) {
			if (s[i]=='1') ar3[i]=ar1[i-1]+ar2[i];
			else ar3[i]=0;
		}
		int q;
		frst(1,0,n-1);
		//temp  
		scanf("%d",&q);
		while (q--) {
			int x, y;
			scanf("%d%d",&x,&y);
			x--; y--;
			int ans=0;
			ans=max(ans,ar2[x]-ar2[y+1]);
			if (x==0) {
				ans=max(ans,ar1[y]);
			}
			else ans=max(ans,ar1[y]-ar1[x-1]);
			int val=query(1,0,n-1,x,y);
			if (x==0) ans=max(ans,val-ar2[y+1]);
			else ans=max(ans,val-ar1[x-1]-ar2[y+1]);
			cout<<ans<<endl;
		}
	}
	return 0;
}
