//I LOVE INDIA
#include <cstdio>
const int N=100100;
struct node { int z,o,best; node() { } };

node st[N<<3],ans[N<<3];

char str[N];
int ppmax(int a,int b) { return a>b?a:b; }

void ppmake(int n,int s,int e)
{
	if(s==e)
	{
		st[n].z=(str[s]=='0');
		st[n].o=1-st[n].z;
		st[n].best=1;
		return;
	}
	int mi=(s+e)/2;
	ppmake(n<<1,s,mi);
	ppmake((n<<1) + 1,mi+1,e);
	st[n].z=st[n<<1].z+st[(n<<1) + 1].z;
	st[n].o=st[n<<1].o+st[(n<<1) + 1].o;
	st[n].best=ppmax(st[n<<1].z+st[(n<<1) + 1].best,st[n<<1].best+st[(n<<1) + 1].o);
}
	
void ppquery(int n,int i,int j,int s,int e)
{
	if(s>=i && e<=j) 
	{
		ans[n]=st[n];
		return;
	}
	if(s>j || e<i)
	{
		ans[n].z=ans[n].o=ans[n].best=0;
		return;
	}
	int mi=(s+e)/2;
	ppquery(n<<1,i,j,s,mi);
	ppquery((n<<1) + 1,i,j,mi+1,e);
	ans[n].z=ans[n<<1].z+ans[(n<<1) + 1].z;
	ans[n].o=ans[n<<1].o+ans[(n<<1) + 1].o;
	ans[n].best=ppmax(ans[n<<1].z+ans[(n<<1) + 1].best,ans[n<<1].best+ans[(n<<1) + 1].o);
}
	
int main()
{
	int t,n,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",str);
		ppmake(1,0,n-1);
		int q;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&i,&j);
			ppquery(1,i-1,j-1,0,n-1);
			printf("%d\n",ans[1].best);
		}
	}
	return 0;
}