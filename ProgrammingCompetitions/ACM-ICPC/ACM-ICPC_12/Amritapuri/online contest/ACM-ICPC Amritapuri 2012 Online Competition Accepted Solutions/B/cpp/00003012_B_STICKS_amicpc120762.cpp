#include <cstdio>

long long l[50030];
int main()
{
	int t,n,m,h,b,w,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		long long max=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			l[i]=(long long)j*j;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&h,&b,&w);
			long long cur=(long long)h*h+(long long)b*b+(long long)w*w;
			if(cur>max) max=cur;
		}
		int ans=0;
		for(i=0;i<n;i++) if(l[i]<=max) ans++;
		printf("%d\n",ans);
	}
	return 0;
}