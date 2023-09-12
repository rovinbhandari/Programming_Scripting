#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int main(){
	int T,n,m,i,ans;
	long double stick[50001],max_stick;
	long double max_box,l,b,h;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		max_stick=max_box=0;
		for (i=0;i<n;i++) scanf("%Lf",&stick[i]),max_stick=max(max_stick,stick[i]);
		for (i=0;i<m;i++) scanf("%Lf%Lf%Lf",&l,&b,&h),max_box=max(max_box,(l*l)+(b*b)+(h*h));
		ans=0;
		for (i=0;i<n;i++) if (stick[i]*stick[i]<=max_box) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
