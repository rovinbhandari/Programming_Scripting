#include<stdio.h>
#define max 20010
#define mod 1000000007
typedef long long int ll;
int q[10*max],a[max+10][100];
ll power(ll n ,ll k)
{
	ll ans=1;
	while(k>0)
	{
		if(k&1)
			ans = (ans*n)%mod;
		k>>=1;
		n = (n * n)%mod;
	}
	return ans%mod;
}
int input()
{
	register int c = getchar_unlocked();
	int x=0;
	while(c<48 || c>57)
		c=getchar_unlocked();
	while(c>=48 && c<=57)
	{
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
int main()
{
	int t=input();
	while(t--)
	{
		int n=input(),x,y,i;
		int color[max]={0},partition[max]={0},j,count=0;
		int ind[max]={0};
		for(i=0;i<n;i++)
		{
			int m = input();
			for(j=0;j<m;j++)
			{			
				y = input();
				a[i][ind[i]++] = y;
				a[y][ind[y]++] = i;
			}
		}
		int check = 1;
		for(j=0;j<n;j++)
		{
			if(color[j])
				continue;
			int l=0,i;
			x = 0;
			color[j] = 1;
			partition[j] = 1;
			q[l++] = j;
			int bipar=1;
			while(x!=l)
			{   
				int u = q[x++];
				int m = ind[u];
				for(i=0;i<m;i++)
				{
					int c = a[u][i];
					if(partition[c]==partition[u])
					{   
						bipar=0;
						break;
					}   
					else if(color[c]==0)
					{   
						color[c] = 1;
						partition[c] = 3-partition[u];
						q[l++] = c;
					}   
				}
				color[u] = 2;
				if(bipar==0)
					break;
			}
			if(!bipar)
			{
				check = 0;
				break;
			}
			count += 1;
		}
		printf("%lld\n",check?power((ll)2,(ll)count):0);
	}
	return 0;
}
