#include <cstdio>
const int N=1024,M=1000020;

int a[N];
int bit[M],temp[M];

void update(int x,int val)
{
	while(x<M)
	{
		bit[x]+=val;
		x+=(x & -x);
	}
}

int get(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=bit[x];
		x-=(x & -x);
	}
	return sum;
}

int main()
{
	int t,n,L,H,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&L,&H);
		long long ans=0;
		for(i=0;i<n;i++) scanf("%d",a+i);
		
		for(i=0;i<M;i++) temp[i]=bit[i];
		for(i=0;i<n;i++)
		{
			for(int ii=i+1;ii<n;ii++) update(a[ii],1);
			for(j=i+1;j<n;j++)
			{
				
				update(a[j],-1);
				int cur=a[i]+a[j];
				int l=L-cur,h=H-cur;
				if(l<0) l=0;
//printf("%d %d %d %d %d\n",i,j,get(h),get(l-1),get(h)-((l==0)?0:get(l-1)));
				ans+=get(h)-((l==0)?0:get(l-1));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}