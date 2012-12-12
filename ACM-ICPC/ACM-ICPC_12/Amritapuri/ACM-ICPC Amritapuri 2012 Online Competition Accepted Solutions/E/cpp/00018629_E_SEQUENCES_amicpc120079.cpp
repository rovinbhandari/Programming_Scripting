#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct t{
	int l,h;
	int a[3];
};

t a[300000]={0,0,{0,0,0}};


int log2(int n)
{
	int y=0;
	int flag=0;
	while(n!=1)
	{
		if(n%2==1)
			flag=1;
		n/=2;
		y++;
	}
	if(flag!=0)
		y++;
	return y;
}

t query(int x,int y,int i)
{
	int m=(a[i].h+a[i].l)/2;
	t ans,ans1,ans2;
	if(a[i].l==x && a[i].h==y)
		ans=a[i];
	else if(x>m)
		ans=query(x,y,2*i+1);
	else if(y<=m)
		ans=query(x,y,2*i);
	else if(x<m+1 && y>m)
	{
		ans=query(x,m,2*i);
		ans1=query(m+1,y,2*i+1);
		ans2.a[0]=ans.a[0]+ans1.a[0];
		ans2.a[1]=ans.a[1]+ans1.a[1];
		ans2.a[2]=max( ans.a[0]+ans1.a[0] , max( ans.a[1]+ans1.a[1] , max(ans.a[0]+ans1.a[1],max(ans.a[0]+ans1.a[2] , ans.a[2]+ans1.a[1]  ) ) ) );
		ans=ans2;
	}
	return ans;
}

char str[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,p,q;
		int i;
		memset(a,0,sizeof(a));
		scanf("%d%s%d",&N,str,&q);
		int n;
		n=log2(N);
		int size=pow((float)2,n);
		int itr=0;
		for(i=size;i<size+N;i++)
		{
			if(str[itr]=='0')
				a[i].a[0]=1;
			else
				a[i].a[1]=1;
			a[i].a[2]=1;
			a[i].l=i-size;
			a[i].h=i-size+1-1;
			itr++;
		}
		int level=size/2;
		int counter=0;
		for(i=size-1;i>0;i--)
		{
			int p1=i*2,p2=i*2+1;
			a[i].a[0]=a[p1].a[0]+a[p2].a[0];
			a[i].a[1]=a[p1].a[1]+a[p2].a[1];
			a[i].a[2]=max( a[p1].a[0]+a[p2].a[0] , max( a[p1].a[1]+a[p2].a[1] , max(a[p1].a[0]+a[p2].a[1],max(a[p1].a[0]+a[p2].a[2] , a[p1].a[2]+a[p2].a[1]  ) ) ) );

			a[i].l=size/level*(i-level);
			a[i].h=size/level*(i-level+1)-1;
			counter++;
			if(counter==level)
			{
				counter=0;
				level/=2;
			}
		}
		int temp;
		for(i=0;i<q;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			t ans;
			ans=query(l-1,r-1,1);
			printf("%d\n",ans.a[2]);
		}
	}
	return 0;
}
